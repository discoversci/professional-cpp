# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/jperme/dev-tools/clion-2024.2.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/jperme/dev-tools/clion-2024.2.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jperme/dev/professional-cpp/example04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jperme/dev/professional-cpp/example04/debug-build

# Include any dependencies generated for this target.
include source/CMakeFiles/library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/library.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/library.dir/flags.make

source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o: source/CMakeFiles/library.dir/flags.make
source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o: /home/jperme/dev/professional-cpp/example04/source/SpreadsheetCell.cpp
source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o: source/CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jperme/dev/professional-cpp/example04/debug-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o -MF CMakeFiles/library.dir/SpreadsheetCell.cpp.o.d -o CMakeFiles/library.dir/SpreadsheetCell.cpp.o -c /home/jperme/dev/professional-cpp/example04/source/SpreadsheetCell.cpp

source/CMakeFiles/library.dir/SpreadsheetCell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/library.dir/SpreadsheetCell.cpp.i"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jperme/dev/professional-cpp/example04/source/SpreadsheetCell.cpp > CMakeFiles/library.dir/SpreadsheetCell.cpp.i

source/CMakeFiles/library.dir/SpreadsheetCell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/library.dir/SpreadsheetCell.cpp.s"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jperme/dev/professional-cpp/example04/source/SpreadsheetCell.cpp -o CMakeFiles/library.dir/SpreadsheetCell.cpp.s

source/CMakeFiles/library.dir/Spreadsheet.cpp.o: source/CMakeFiles/library.dir/flags.make
source/CMakeFiles/library.dir/Spreadsheet.cpp.o: /home/jperme/dev/professional-cpp/example04/source/Spreadsheet.cpp
source/CMakeFiles/library.dir/Spreadsheet.cpp.o: source/CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jperme/dev/professional-cpp/example04/debug-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/library.dir/Spreadsheet.cpp.o"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/library.dir/Spreadsheet.cpp.o -MF CMakeFiles/library.dir/Spreadsheet.cpp.o.d -o CMakeFiles/library.dir/Spreadsheet.cpp.o -c /home/jperme/dev/professional-cpp/example04/source/Spreadsheet.cpp

source/CMakeFiles/library.dir/Spreadsheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/library.dir/Spreadsheet.cpp.i"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jperme/dev/professional-cpp/example04/source/Spreadsheet.cpp > CMakeFiles/library.dir/Spreadsheet.cpp.i

source/CMakeFiles/library.dir/Spreadsheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/library.dir/Spreadsheet.cpp.s"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jperme/dev/professional-cpp/example04/source/Spreadsheet.cpp -o CMakeFiles/library.dir/Spreadsheet.cpp.s

source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o: source/CMakeFiles/library.dir/flags.make
source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o: /home/jperme/dev/professional-cpp/example04/source/SpreadsheetApplication.cpp
source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o: source/CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jperme/dev/professional-cpp/example04/debug-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o -MF CMakeFiles/library.dir/SpreadsheetApplication.cpp.o.d -o CMakeFiles/library.dir/SpreadsheetApplication.cpp.o -c /home/jperme/dev/professional-cpp/example04/source/SpreadsheetApplication.cpp

source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/library.dir/SpreadsheetApplication.cpp.i"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jperme/dev/professional-cpp/example04/source/SpreadsheetApplication.cpp > CMakeFiles/library.dir/SpreadsheetApplication.cpp.i

source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/library.dir/SpreadsheetApplication.cpp.s"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jperme/dev/professional-cpp/example04/source/SpreadsheetApplication.cpp -o CMakeFiles/library.dir/SpreadsheetApplication.cpp.s

source/CMakeFiles/library.dir/Operators.cpp.o: source/CMakeFiles/library.dir/flags.make
source/CMakeFiles/library.dir/Operators.cpp.o: /home/jperme/dev/professional-cpp/example04/source/Operators.cpp
source/CMakeFiles/library.dir/Operators.cpp.o: source/CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jperme/dev/professional-cpp/example04/debug-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/CMakeFiles/library.dir/Operators.cpp.o"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/library.dir/Operators.cpp.o -MF CMakeFiles/library.dir/Operators.cpp.o.d -o CMakeFiles/library.dir/Operators.cpp.o -c /home/jperme/dev/professional-cpp/example04/source/Operators.cpp

source/CMakeFiles/library.dir/Operators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/library.dir/Operators.cpp.i"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jperme/dev/professional-cpp/example04/source/Operators.cpp > CMakeFiles/library.dir/Operators.cpp.i

source/CMakeFiles/library.dir/Operators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/library.dir/Operators.cpp.s"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jperme/dev/professional-cpp/example04/source/Operators.cpp -o CMakeFiles/library.dir/Operators.cpp.s

# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/SpreadsheetCell.cpp.o" \
"CMakeFiles/library.dir/Spreadsheet.cpp.o" \
"CMakeFiles/library.dir/SpreadsheetApplication.cpp.o" \
"CMakeFiles/library.dir/Operators.cpp.o"

# External object files for target library
library_EXTERNAL_OBJECTS =

source/liblibrary.a: source/CMakeFiles/library.dir/SpreadsheetCell.cpp.o
source/liblibrary.a: source/CMakeFiles/library.dir/Spreadsheet.cpp.o
source/liblibrary.a: source/CMakeFiles/library.dir/SpreadsheetApplication.cpp.o
source/liblibrary.a: source/CMakeFiles/library.dir/Operators.cpp.o
source/liblibrary.a: source/CMakeFiles/library.dir/build.make
source/liblibrary.a: source/CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jperme/dev/professional-cpp/example04/debug-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library liblibrary.a"
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean_target.cmake
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/library.dir/build: source/liblibrary.a
.PHONY : source/CMakeFiles/library.dir/build

source/CMakeFiles/library.dir/clean:
	cd /home/jperme/dev/professional-cpp/example04/debug-build/source && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/library.dir/clean

source/CMakeFiles/library.dir/depend:
	cd /home/jperme/dev/professional-cpp/example04/debug-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jperme/dev/professional-cpp/example04 /home/jperme/dev/professional-cpp/example04/source /home/jperme/dev/professional-cpp/example04/debug-build /home/jperme/dev/professional-cpp/example04/debug-build/source /home/jperme/dev/professional-cpp/example04/debug-build/source/CMakeFiles/library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/CMakeFiles/library.dir/depend

