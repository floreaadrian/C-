# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab5_6STL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab5_6STL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab5_6STL.dir/flags.make

CMakeFiles/Lab5_6STL.dir/main.cpp.o: CMakeFiles/Lab5_6STL.dir/flags.make
CMakeFiles/Lab5_6STL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab5_6STL.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab5_6STL.dir/main.cpp.o -c /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/main.cpp

CMakeFiles/Lab5_6STL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab5_6STL.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/main.cpp > CMakeFiles/Lab5_6STL.dir/main.cpp.i

CMakeFiles/Lab5_6STL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab5_6STL.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/main.cpp -o CMakeFiles/Lab5_6STL.dir/main.cpp.s

CMakeFiles/Lab5_6STL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lab5_6STL.dir/main.cpp.o.requires

CMakeFiles/Lab5_6STL.dir/main.cpp.o.provides: CMakeFiles/Lab5_6STL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab5_6STL.dir/build.make CMakeFiles/Lab5_6STL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lab5_6STL.dir/main.cpp.o.provides

CMakeFiles/Lab5_6STL.dir/main.cpp.o.provides.build: CMakeFiles/Lab5_6STL.dir/main.cpp.o


# Object files for target Lab5_6STL
Lab5_6STL_OBJECTS = \
"CMakeFiles/Lab5_6STL.dir/main.cpp.o"

# External object files for target Lab5_6STL
Lab5_6STL_EXTERNAL_OBJECTS =

Lab5_6STL: CMakeFiles/Lab5_6STL.dir/main.cpp.o
Lab5_6STL: CMakeFiles/Lab5_6STL.dir/build.make
Lab5_6STL: CMakeFiles/Lab5_6STL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab5_6STL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab5_6STL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab5_6STL.dir/build: Lab5_6STL

.PHONY : CMakeFiles/Lab5_6STL.dir/build

CMakeFiles/Lab5_6STL.dir/requires: CMakeFiles/Lab5_6STL.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lab5_6STL.dir/requires

CMakeFiles/Lab5_6STL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab5_6STL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab5_6STL.dir/clean

CMakeFiles/Lab5_6STL.dir/depend:
	cd /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug /Users/adrianflorea/Codes/C++/OOP/Lab5-6STL/cmake-build-debug/CMakeFiles/Lab5_6STL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab5_6STL.dir/depend

