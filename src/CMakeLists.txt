cmake_minimum_required(VERSION 3.10)
project(fstcpp VERSION 1.0.0)

# Find dependencies
find_package(ZLIB REQUIRED)
find_package(GTest REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Coverage
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if(ENABLE_COVERAGE)
    set(CMAKE_BUILD_TYPE Debug)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-sign-compare)
elseif (MSVC)
    add_compile_options(/W4)
endif()

# Include current source directory for headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#######################################
# build our FST library
#######################################

# Collect cpp files (recursively) and split regular library sources vs tests (files ending with ".test.cpp")
file(GLOB_RECURSE FST_CPP_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/fstcpp/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/gtkwave/*.cpp"
)

# Lists to populate
# We have 2 lists
# 1. FSTCPP_SRCS - all non-test source files
# 2. FSTCPP_TEST_MAIN - all test source files that will be compiled into executables and run by ctest (ending with .test.cpp)
set(FSTCPP_SRCS "")
set(FSTCPP_TEST_MAIN "")

foreach(FP ${FST_CPP_FILES})
    # get the filename with extension, e.g. "Writer.test.cpp"
    get_filename_component(FNAME ${FP} NAME)
    if(FNAME MATCHES ".*\\.test\\.cpp$")
        list(APPEND FSTCPP_TEST_MAIN "${FP}")
    else()
        list(APPEND FSTCPP_SRCS "${FP}")
    endif()
endforeach()

# Create fstcpp library from non-test sources
add_library(fstcpp STATIC ${FSTCPP_SRCS})
target_include_directories(fstcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fstcpp PUBLIC ZLIB::ZLIB lz4)
# Core library shall only be built with C++14
set_target_properties(fstcpp PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES)

# Build unittest targets for each *.test.cpp and register with CTest
enable_testing()
foreach(TEST_SRC ${FSTCPP_TEST_MAIN})
    get_filename_component(TEST_NAME_WE ${TEST_SRC} NAME_WE)
    # sanitize a valid CMake target name (replace dots with underscores)
    string(REPLACE "." "_" TEST_TARGET ${TEST_NAME_WE})
    add_executable(${TEST_TARGET} ${TEST_SRC})
    target_link_libraries(${TEST_TARGET} PRIVATE fstcpp GTest::GTest GTest::Main)
    add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})
endforeach()

#######################################
# Build the integration tests for testing bit-true behavior
#######################################
# compile verilator_shared/*.cpp as an cmake object
file(
    GLOB_RECURSE
    VERILATOR_SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/integration_test/verilator_share/*.cpp
)
add_library(verilator_shared OBJECT ${VERILATOR_SHARED})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/integration_test/verilator_share)

# for all direct folders under integration_test/tests, find all *.cpp files and compile them as an executable
file(GLOB TEST_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/integration_test/tests/*)

foreach(TEST_PATH ${TEST_PATHS})
    get_filename_component(TEST_NAME ${TEST_PATH} NAME)

    # ensure it is a directory
    if(IS_DIRECTORY ${TEST_PATH})
        # compile all *.cpp files in the folder as an executable
        file(GLOB_RECURSE TEST_SRCS ${TEST_PATH}/*.cpp)

        # C executable
        add_executable(${TEST_NAME}_c ${TEST_SRCS} gtkwave/fstapi.c $<TARGET_OBJECTS:verilator_shared>)
        target_link_libraries(${TEST_NAME}_c PRIVATE fstcpp)
        target_include_directories(${TEST_NAME}_c PRIVATE ${TEST_PATH}/verilated)
        add_test(NAME ${TEST_NAME}_c COMMAND ${TEST_NAME}_c ${TEST_NAME}_dump_c.fst)

        # C++ executable
        add_executable(${TEST_NAME}_cpp ${TEST_SRCS} gtkwave/fstapi.cpp $<TARGET_OBJECTS:verilator_shared>)
        target_link_libraries(${TEST_NAME}_cpp PRIVATE fstcpp)
        target_include_directories(${TEST_NAME}_cpp PRIVATE ${TEST_PATH}/verilated)
        add_test(NAME ${TEST_NAME}_cpp COMMAND ${TEST_NAME}_cpp ${TEST_NAME}_dump_cpp.fst)

        # must be bit-true
        add_test(
            NAME ${TEST_NAME}_compare
            COMMAND ${CMAKE_COMMAND} -E compare_files ${TEST_NAME}_dump_cpp.fst ${TEST_NAME}_dump_c.fst
        )
        set_tests_properties(
            ${TEST_NAME}_compare
            PROPERTIES
            DEPENDS "${TEST_NAME}_cpp;${TEST_NAME}_c"
        )
    endif()
endforeach()

#######################################
# Lint
#######################################
file(GLOB LINT_HEADER "fstcpp/*.h")
file(GLOB LINT_CPP "fstcpp/*.cpp")
list(FILTER LINT_CPP EXCLUDE REGEX ".*\\.test\\.cpp$")
set(CLANG_TIDY_FLAGS
    "-config={}"
    "-checks=-fuchsia-*,-cppcoreguidelines-avoid-c-arrays,-cppcoreguidelines-init-variables,-cppcoreguidelines-avoid-goto,-modernize-avoid-c-arrays,-readability-magic-numbers,-readability-simplify-boolean-expr,-cppcoreguidelines-macro-usage"
)
set(CPPCHECK_FLAGS
    "-I${CMAKE_CURRENT_SOURCE_DIR}"
    "--enable=all"
    "--inline-suppr"
)

set(CLANG_TIDY_TARGETS "")
set(CPPCHECK_TARGETS "")

# add to both clang-tidy and cppcheck
foreach(FILE ${LINT_CPP})
    # Extract a valid TARGET_NAME
    get_filename_component(FILENAME ${FILE} NAME)
    string(MAKE_C_IDENTIFIER ${FILENAME} TARGET_NAME)

    add_custom_target(clang_tidy_${TARGET_NAME}
        COMMAND ${CLANG_TIDY}
            ${CLANG_TIDY_FLAGS}
            ${FILE}
            --
            -x c++
            -I ${CMAKE_CURRENT_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
    add_custom_target(cppcheck_${TARGET_NAME}
        COMMAND ${CPPCHECK}
            ${CPPCHECK_FLAGS}
            ${FILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
    list(APPEND CLANG_TIDY_TARGETS clang_tidy_${TARGET_NAME})
    list(APPEND CPPCHECK_TARGETS cppcheck_${TARGET_NAME})
endforeach()

# add to clang-tidy
foreach(FILE ${LINT_HEADER})
    # Extract a valid TARGET_NAME
    get_filename_component(FILENAME ${FILE} NAME)
    string(MAKE_C_IDENTIFIER ${FILENAME} TARGET_NAME)

    add_custom_target(clang_tidy_${TARGET_NAME}
        COMMAND ${CLANG_TIDY}
            ${CLANG_TIDY_FLAGS}
            ${FILE}
            --
            -x c++-header
            -I ${CMAKE_CURRENT_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
    list(APPEND CLANG_TIDY_TARGETS clang_tidy_${TARGET_NAME})
endforeach()

add_custom_target(clang-tidy DEPENDS ${CLANG_TIDY_TARGETS})
add_custom_target(cppcheck DEPENDS ${CPPCHECK_TARGETS})
