# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ajay/local/miniob

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ajay/local/miniob/build

# Include any dependencies generated for this target.
include unittest/CMakeFiles/log_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include unittest/CMakeFiles/log_test.dir/compiler_depend.make

# Include the progress variables for this target.
include unittest/CMakeFiles/log_test.dir/progress.make

# Include the compile flags for this target's objects.
include unittest/CMakeFiles/log_test.dir/flags.make

unittest/CMakeFiles/log_test.dir/log_test.cpp.o: unittest/CMakeFiles/log_test.dir/flags.make
unittest/CMakeFiles/log_test.dir/log_test.cpp.o: ../unittest/log_test.cpp
unittest/CMakeFiles/log_test.dir/log_test.cpp.o: unittest/CMakeFiles/log_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ajay/local/miniob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unittest/CMakeFiles/log_test.dir/log_test.cpp.o"
	cd /home/ajay/local/miniob/build/unittest && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unittest/CMakeFiles/log_test.dir/log_test.cpp.o -MF CMakeFiles/log_test.dir/log_test.cpp.o.d -o CMakeFiles/log_test.dir/log_test.cpp.o -c /home/ajay/local/miniob/unittest/log_test.cpp

unittest/CMakeFiles/log_test.dir/log_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log_test.dir/log_test.cpp.i"
	cd /home/ajay/local/miniob/build/unittest && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ajay/local/miniob/unittest/log_test.cpp > CMakeFiles/log_test.dir/log_test.cpp.i

unittest/CMakeFiles/log_test.dir/log_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log_test.dir/log_test.cpp.s"
	cd /home/ajay/local/miniob/build/unittest && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ajay/local/miniob/unittest/log_test.cpp -o CMakeFiles/log_test.dir/log_test.cpp.s

# Object files for target log_test
log_test_OBJECTS = \
"CMakeFiles/log_test.dir/log_test.cpp.o"

# External object files for target log_test
log_test_EXTERNAL_OBJECTS =

bin/log_test: unittest/CMakeFiles/log_test.dir/log_test.cpp.o
bin/log_test: unittest/CMakeFiles/log_test.dir/build.make
bin/log_test: lib/libcommon.a
bin/log_test: lib/libobserver.a
bin/log_test: lib/libcommon.a
bin/log_test: /usr/local/lib/libevent_pthreads.a
bin/log_test: /usr/local/lib/libevent_core.a
bin/log_test: unittest/CMakeFiles/log_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ajay/local/miniob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/log_test"
	cd /home/ajay/local/miniob/build/unittest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ajay/local/miniob/build/unittest && /usr/bin/cmake -D TEST_TARGET=log_test -D TEST_EXECUTABLE=/home/ajay/local/miniob/build/bin/log_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/ajay/local/miniob/build/unittest -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=log_test_TESTS -D CTEST_FILE=/home/ajay/local/miniob/build/unittest/log_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
unittest/CMakeFiles/log_test.dir/build: bin/log_test
.PHONY : unittest/CMakeFiles/log_test.dir/build

unittest/CMakeFiles/log_test.dir/clean:
	cd /home/ajay/local/miniob/build/unittest && $(CMAKE_COMMAND) -P CMakeFiles/log_test.dir/cmake_clean.cmake
.PHONY : unittest/CMakeFiles/log_test.dir/clean

unittest/CMakeFiles/log_test.dir/depend:
	cd /home/ajay/local/miniob/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ajay/local/miniob /home/ajay/local/miniob/unittest /home/ajay/local/miniob/build /home/ajay/local/miniob/build/unittest /home/ajay/local/miniob/build/unittest/CMakeFiles/log_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittest/CMakeFiles/log_test.dir/depend

