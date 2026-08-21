#!/bin/bash
set -e
# Change to the directory of this script
cd "$(dirname "$(realpath "$0")")"

# Settings
VERILATOR_SHARE="verilator_share"

# Copy Verilator Runtime (you need to install Verilator first)
echo "=== Copying Verilator Runtime ==="
VERILATOR_ROOT=$(verilator -V | grep VERILATOR_ROOT | head -1 | awk '{print $3}')
echo "Using VERILATOR_ROOT: $VERILATOR_ROOT"

SOURCE_DIR="$VERILATOR_ROOT/include"
# if not found, try to find the executable path's ../include
if [ ! -d "$SOURCE_DIR" ]; then
    SOURCE_DIR="$(dirname "$(which verilator)")/../include"
fi
# (We can add more fallback paths here)
# give up if not found
if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Could not find Verilator include directory at $SOURCE_DIR"
    exit 1
fi

mkdir -p "$VERILATOR_SHARE"
# Copy Verilator include files to verilator_share
# We don't remove verilator_share because it contains patches we need!
cp -r "$SOURCE_DIR"/*.cpp "$SOURCE_DIR"/*.h "$SOURCE_DIR"/vltstd "$VERILATOR_SHARE"/

# Filter files (Whitelisting): Remove files containing _sc _vcd, followed by . or _
rm -rf "$VERILATOR_SHARE"/*_sc[._]* "$VERILATOR_SHARE"/*_vcd[._]*

# Apply patches in verilator_share if Verilator is not already using fstcpp
if [ ! -d "${SOURCE_DIR}/fstcpp" ]; then
    echo "=== Applying patches in $VERILATOR_SHARE/ ==="
    for patch_file in "$VERILATOR_SHARE"/*.patch; do
        if [ -f "$patch_file" ]; then
            target="${patch_file%.patch}"
            echo "Applying patch: $patch_file -> $target"
            # We use -f to force apply even if it seems already applied (e.g. if script rerun)
            # But actually, since we just copied fresh files from SOURCE_DIR, they are NOT patched yet.
            patch "$target" < "$patch_file"
        fi
    done
fi

echo "=== Generating Verilated files for integration tests ==="
for test_dir in tests/*; do
    if [ -d "$test_dir" ] && [ -f "$test_dir/Makefile" ]; then
        echo ">>> Building $test_dir..."
        rm -rf "${test_dir}/verilated"
        make -C "$test_dir"
    fi
done

echo "=== Verilator setup complete ==="
