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
CMAKE_SOURCE_DIR = /home/aebov/bp-sudoku

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aebov/bp-sudoku/build

# Include any dependencies generated for this target.
include CMakeFiles/sudoku.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sudoku.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku.dir/flags.make

CMakeFiles/sudoku.dir/sudoku.cpp.o: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/sudoku.cpp.o: ../sudoku.cpp
CMakeFiles/sudoku.dir/sudoku.cpp.o: CMakeFiles/sudoku.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aebov/bp-sudoku/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sudoku.dir/sudoku.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sudoku.dir/sudoku.cpp.o -MF CMakeFiles/sudoku.dir/sudoku.cpp.o.d -o CMakeFiles/sudoku.dir/sudoku.cpp.o -c /home/aebov/bp-sudoku/sudoku.cpp

CMakeFiles/sudoku.dir/sudoku.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/sudoku.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aebov/bp-sudoku/sudoku.cpp > CMakeFiles/sudoku.dir/sudoku.cpp.i

CMakeFiles/sudoku.dir/sudoku.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/sudoku.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aebov/bp-sudoku/sudoku.cpp -o CMakeFiles/sudoku.dir/sudoku.cpp.s

# Object files for target sudoku
sudoku_OBJECTS = \
"CMakeFiles/sudoku.dir/sudoku.cpp.o"

# External object files for target sudoku
sudoku_EXTERNAL_OBJECTS =

sudoku: CMakeFiles/sudoku.dir/sudoku.cpp.o
sudoku: CMakeFiles/sudoku.dir/build.make
sudoku: src/file/libfile.a
sudoku: src/core/libcore.a
sudoku: src/user/libuser.a
sudoku: /usr/lib/x86_64-linux-gnu/libcurses.so
sudoku: /usr/lib/x86_64-linux-gnu/libform.so
sudoku: CMakeFiles/sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aebov/bp-sudoku/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sudoku"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sudoku.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku.dir/build: sudoku
.PHONY : CMakeFiles/sudoku.dir/build

CMakeFiles/sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sudoku.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sudoku.dir/clean

CMakeFiles/sudoku.dir/depend:
	cd /home/aebov/bp-sudoku/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aebov/bp-sudoku /home/aebov/bp-sudoku /home/aebov/bp-sudoku/build /home/aebov/bp-sudoku/build /home/aebov/bp-sudoku/build/CMakeFiles/sudoku.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sudoku.dir/depend

