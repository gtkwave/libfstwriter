#!/bin/bash

# Argparse
# --help, print help message
# --build <build_dir>, default to ./build/regression
# --coverage, default to false
# --coverage-html, default to false, autoset --coverage to true
# --coverage-line, default to 70
# --coverage-func, default to 70
BUILD_DIR="build/regression"
COVERAGE=0
COVERAGE_HTML=0
COVERAGE_LINE=70
COVERAGE_FUNC=70
ROOT_DIR=$(pwd)
TEST_EXIT_CODE=0
while [[ "$#" -gt 0 ]]; do
	case $1 in
		--help) echo "Usage: $0 [--build <build_dir>] [--coverage] [--coverage-html] [--coverage-line <line_percent>] [--coverage-func <func_percent>]"; exit 0;;
		--build) shift; BUILD_DIR=$1;;
		--coverage) shift; COVERAGE=1;;
		--coverage-html) shift; COVERAGE_HTML=1; COVERAGE=1;;
		--coverage-line) shift; COVERAGE_LINE=$1;;
		--coverage-func) shift; COVERAGE_FUNC=$1;;
		*) echo "Unknown option: $1"; exit 1;;
	esac
	shift
done

function CMakeInit() {
	rm -rf "$BUILD_DIR"
	mkdir -p "$BUILD_DIR"
	local cov_opt="OFF"
	if [ $COVERAGE -eq 1 ]; then cov_opt="ON"; fi
	cmake -B "$BUILD_DIR" -S src -G Ninja -DENABLE_COVERAGE=$cov_opt
}

function BuildAndRunTests() {
	ninja -j$(nproc) || return 1
	ctest -j$(nproc) --output-on-failure | tee ctest.log
	TEST_EXIT_CODE=${PIPESTATUS[0]}
}

function CollectCoverage() {
	if [ $COVERAGE = 1 ]; then
		lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent,mismatch,empty
		lcov --extract coverage.info '*/src/fstcpp/*' --output-file coverage.info --ignore-errors inconsistent,mismatch,empty
		if [ $COVERAGE_HTML = 1 ]; then
			genhtml coverage.info --output-directory html
		fi
	fi
}

function GenerateResults() {
	echo "### Test Results"
	local summary_line=$(grep "tests passed" ctest.log | tail -1)
	echo "$summary_line"
	if [ "$TEST_EXIT_CODE" -ne 0 ]; then
		echo ""
		echo "#### Failed Tests"
		grep "The following tests FAILED:" -A 100 ctest.log
	fi

	if [ $COVERAGE = 1 ]; then
		echo ""
		echo "### Coverage Summary"
		lcov --summary coverage.info > coverage_summary.txt 2>&1
		cat coverage_summary.txt

		local line_cov=$(grep "lines" coverage_summary.txt | grep -o "[0-9.]*%" | head -1 | tr -d '%')
		local func_cov=$(grep "functions" coverage_summary.txt | grep -o "[0-9.]*%" | head -1 | tr -d '%')

		local line_pass=$(awk -v cov="$line_cov" -v thr="$COVERAGE_LINE" 'BEGIN {print (cov >= thr) ? 1 : 0}')
		local func_pass=$(awk -v cov="$func_cov" -v thr="$COVERAGE_FUNC" 'BEGIN {print (cov >= thr) ? 1 : 0}')

		if [ "$line_pass" -eq 0 ]; then
			echo "Error: Line coverage $line_cov% is below threshold $COVERAGE_LINE%"
			TEST_EXIT_CODE=1
		fi
		if [ "$func_pass" -eq 0 ]; then
			echo "Error: Function coverage $func_cov% is below threshold $COVERAGE_FUNC%"
			TEST_EXIT_CODE=1
		fi
	fi

	if [ "$TEST_EXIT_CODE" -ne 0 ]; then
		return 1
	fi
}

######################################
# main part of this script
######################################
echo "Running regression test..."

echo "1/4 CMake..."
CMakeInit || { echo "Failed to run CMake"; exit 1; }

# Everything after this point is in the build directory
cd "$BUILD_DIR"

echo "2/4 Building and running tests..."
BuildAndRunTests || { echo "Failed to build and run tests"; exit 1; }

echo "3/4 Collecting coverage..."
CollectCoverage || { echo "Failed to collect coverage"; exit 1; }

echo "4/4 Generating results..."
GenerateResults > "regression_results.md"
GEN_RES=$?
cat "regression_results.md"

if [ -n "$GITHUB_STEP_SUMMARY" ]; then
	cat "regression_results.md" >> "$GITHUB_STEP_SUMMARY"
fi

if [ $GEN_RES -ne 0 ]; then
	TEST_EXIT_CODE=1
fi

exit $TEST_EXIT_CODE
