# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adrianflorea/C++/CodeChef

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adrianflorea/C++/CodeChef/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CodeChef.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeChef.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeChef.dir/flags.make

CMakeFiles/CodeChef.dir/MAXSC.cpp.o: CMakeFiles/CodeChef.dir/flags.make
CMakeFiles/CodeChef.dir/MAXSC.cpp.o: ../MAXSC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adrianflorea/C++/CodeChef/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeChef.dir/MAXSC.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeChef.dir/MAXSC.cpp.o -c /Users/adrianflorea/C++/CodeChef/MAXSC.cpp

CMakeFiles/CodeChef.dir/MAXSC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeChef.dir/MAXSC.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adrianflorea/C++/CodeChef/MAXSC.cpp > CMakeFiles/CodeChef.dir/MAXSC.cpp.i

CMakeFiles/CodeChef.dir/MAXSC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeChef.dir/MAXSC.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adrianflorea/C++/CodeChef/MAXSC.cpp -o CMakeFiles/CodeChef.dir/MAXSC.cpp.s

CMakeFiles/CodeChef.dir/MAXSC.cpp.o.requires:

.PHONY : CMakeFiles/CodeChef.dir/MAXSC.cpp.o.requires

CMakeFiles/CodeChef.dir/MAXSC.cpp.o.provides: CMakeFiles/CodeChef.dir/MAXSC.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeChef.dir/build.make CMakeFiles/CodeChef.dir/MAXSC.cpp.o.provides.build
.PHONY : CMakeFiles/CodeChef.dir/MAXSC.cpp.o.provides

CMakeFiles/CodeChef.dir/MAXSC.cpp.o.provides.build: CMakeFiles/CodeChef.dir/MAXSC.cpp.o


# Object files for target CodeChef
CodeChef_OBJECTS = \
"CMakeFiles/CodeChef.dir/MAXSC.cpp.o"

# External object files for target CodeChef
CodeChef_EXTERNAL_OBJECTS =

CodeChef: CMakeFiles/CodeChef.dir/MAXSC.cpp.o
CodeChef: CMakeFiles/CodeChef.dir/build.make
CodeChef: CMakeFiles/CodeChef.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adrianflorea/C++/CodeChef/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CodeChef"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeChef.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeChef.dir/build: CodeChef

.PHONY : CMakeFiles/CodeChef.dir/build

CMakeFiles/CodeChef.dir/requires: CMakeFiles/CodeChef.dir/MAXSC.cpp.o.requires

.PHONY : CMakeFiles/CodeChef.dir/requires

CMakeFiles/CodeChef.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeChef.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeChef.dir/clean

CMakeFiles/CodeChef.dir/depend:
	cd /Users/adrianflorea/C++/CodeChef/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adrianflorea/C++/CodeChef /Users/adrianflorea/C++/CodeChef /Users/adrianflorea/C++/CodeChef/cmake-build-debug /Users/adrianflorea/C++/CodeChef/cmake-build-debug /Users/adrianflorea/C++/CodeChef/cmake-build-debug/CMakeFiles/CodeChef.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeChef.dir/depend

