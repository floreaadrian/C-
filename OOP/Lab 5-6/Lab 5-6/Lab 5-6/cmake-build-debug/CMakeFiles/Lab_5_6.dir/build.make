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
CMAKE_SOURCE_DIR = "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_5_6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_5_6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_5_6.dir/flags.make

CMakeFiles/Lab_5_6.dir/Controller.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/Controller.o: ../Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_5_6.dir/Controller.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/Controller.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Controller.cpp"

CMakeFiles/Lab_5_6.dir/Controller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/Controller.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Controller.cpp" > CMakeFiles/Lab_5_6.dir/Controller.i

CMakeFiles/Lab_5_6.dir/Controller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/Controller.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Controller.cpp" -o CMakeFiles/Lab_5_6.dir/Controller.s

CMakeFiles/Lab_5_6.dir/Controller.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/Controller.o.requires

CMakeFiles/Lab_5_6.dir/Controller.o.provides: CMakeFiles/Lab_5_6.dir/Controller.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/Controller.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/Controller.o.provides

CMakeFiles/Lab_5_6.dir/Controller.o.provides.build: CMakeFiles/Lab_5_6.dir/Controller.o


CMakeFiles/Lab_5_6.dir/DynamicArray.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/DynamicArray.o: ../DynamicArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_5_6.dir/DynamicArray.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/DynamicArray.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/DynamicArray.cpp"

CMakeFiles/Lab_5_6.dir/DynamicArray.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/DynamicArray.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/DynamicArray.cpp" > CMakeFiles/Lab_5_6.dir/DynamicArray.i

CMakeFiles/Lab_5_6.dir/DynamicArray.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/DynamicArray.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/DynamicArray.cpp" -o CMakeFiles/Lab_5_6.dir/DynamicArray.s

CMakeFiles/Lab_5_6.dir/DynamicArray.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/DynamicArray.o.requires

CMakeFiles/Lab_5_6.dir/DynamicArray.o.provides: CMakeFiles/Lab_5_6.dir/DynamicArray.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/DynamicArray.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/DynamicArray.o.provides

CMakeFiles/Lab_5_6.dir/DynamicArray.o.provides.build: CMakeFiles/Lab_5_6.dir/DynamicArray.o


CMakeFiles/Lab_5_6.dir/Filter.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/Filter.o: ../Filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab_5_6.dir/Filter.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/Filter.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Filter.cpp"

CMakeFiles/Lab_5_6.dir/Filter.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/Filter.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Filter.cpp" > CMakeFiles/Lab_5_6.dir/Filter.i

CMakeFiles/Lab_5_6.dir/Filter.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/Filter.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Filter.cpp" -o CMakeFiles/Lab_5_6.dir/Filter.s

CMakeFiles/Lab_5_6.dir/Filter.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/Filter.o.requires

CMakeFiles/Lab_5_6.dir/Filter.o.provides: CMakeFiles/Lab_5_6.dir/Filter.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/Filter.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/Filter.o.provides

CMakeFiles/Lab_5_6.dir/Filter.o.provides.build: CMakeFiles/Lab_5_6.dir/Filter.o


CMakeFiles/Lab_5_6.dir/main.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab_5_6.dir/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/main.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/main.cpp"

CMakeFiles/Lab_5_6.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/main.cpp" > CMakeFiles/Lab_5_6.dir/main.i

CMakeFiles/Lab_5_6.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/main.cpp" -o CMakeFiles/Lab_5_6.dir/main.s

CMakeFiles/Lab_5_6.dir/main.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/main.o.requires

CMakeFiles/Lab_5_6.dir/main.o.provides: CMakeFiles/Lab_5_6.dir/main.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/main.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/main.o.provides

CMakeFiles/Lab_5_6.dir/main.o.provides.build: CMakeFiles/Lab_5_6.dir/main.o


CMakeFiles/Lab_5_6.dir/Repo.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/Repo.o: ../Repo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lab_5_6.dir/Repo.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/Repo.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Repo.cpp"

CMakeFiles/Lab_5_6.dir/Repo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/Repo.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Repo.cpp" > CMakeFiles/Lab_5_6.dir/Repo.i

CMakeFiles/Lab_5_6.dir/Repo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/Repo.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Repo.cpp" -o CMakeFiles/Lab_5_6.dir/Repo.s

CMakeFiles/Lab_5_6.dir/Repo.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/Repo.o.requires

CMakeFiles/Lab_5_6.dir/Repo.o.provides: CMakeFiles/Lab_5_6.dir/Repo.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/Repo.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/Repo.o.provides

CMakeFiles/Lab_5_6.dir/Repo.o.provides.build: CMakeFiles/Lab_5_6.dir/Repo.o


CMakeFiles/Lab_5_6.dir/Tutorial.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/Tutorial.o: ../Tutorial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Lab_5_6.dir/Tutorial.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/Tutorial.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Tutorial.cpp"

CMakeFiles/Lab_5_6.dir/Tutorial.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/Tutorial.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Tutorial.cpp" > CMakeFiles/Lab_5_6.dir/Tutorial.i

CMakeFiles/Lab_5_6.dir/Tutorial.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/Tutorial.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Tutorial.cpp" -o CMakeFiles/Lab_5_6.dir/Tutorial.s

CMakeFiles/Lab_5_6.dir/Tutorial.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/Tutorial.o.requires

CMakeFiles/Lab_5_6.dir/Tutorial.o.provides: CMakeFiles/Lab_5_6.dir/Tutorial.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/Tutorial.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/Tutorial.o.provides

CMakeFiles/Lab_5_6.dir/Tutorial.o.provides.build: CMakeFiles/Lab_5_6.dir/Tutorial.o


CMakeFiles/Lab_5_6.dir/UI.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/UI.o: ../UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Lab_5_6.dir/UI.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/UI.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/UI.cpp"

CMakeFiles/Lab_5_6.dir/UI.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/UI.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/UI.cpp" > CMakeFiles/Lab_5_6.dir/UI.i

CMakeFiles/Lab_5_6.dir/UI.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/UI.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/UI.cpp" -o CMakeFiles/Lab_5_6.dir/UI.s

CMakeFiles/Lab_5_6.dir/UI.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/UI.o.requires

CMakeFiles/Lab_5_6.dir/UI.o.provides: CMakeFiles/Lab_5_6.dir/UI.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/UI.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/UI.o.provides

CMakeFiles/Lab_5_6.dir/UI.o.provides.build: CMakeFiles/Lab_5_6.dir/UI.o


CMakeFiles/Lab_5_6.dir/Watchlist.o: CMakeFiles/Lab_5_6.dir/flags.make
CMakeFiles/Lab_5_6.dir/Watchlist.o: ../Watchlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Lab_5_6.dir/Watchlist.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5_6.dir/Watchlist.o -c "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Watchlist.cpp"

CMakeFiles/Lab_5_6.dir/Watchlist.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5_6.dir/Watchlist.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Watchlist.cpp" > CMakeFiles/Lab_5_6.dir/Watchlist.i

CMakeFiles/Lab_5_6.dir/Watchlist.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5_6.dir/Watchlist.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/Watchlist.cpp" -o CMakeFiles/Lab_5_6.dir/Watchlist.s

CMakeFiles/Lab_5_6.dir/Watchlist.o.requires:

.PHONY : CMakeFiles/Lab_5_6.dir/Watchlist.o.requires

CMakeFiles/Lab_5_6.dir/Watchlist.o.provides: CMakeFiles/Lab_5_6.dir/Watchlist.o.requires
	$(MAKE) -f CMakeFiles/Lab_5_6.dir/build.make CMakeFiles/Lab_5_6.dir/Watchlist.o.provides.build
.PHONY : CMakeFiles/Lab_5_6.dir/Watchlist.o.provides

CMakeFiles/Lab_5_6.dir/Watchlist.o.provides.build: CMakeFiles/Lab_5_6.dir/Watchlist.o


# Object files for target Lab_5_6
Lab_5_6_OBJECTS = \
"CMakeFiles/Lab_5_6.dir/Controller.o" \
"CMakeFiles/Lab_5_6.dir/DynamicArray.o" \
"CMakeFiles/Lab_5_6.dir/Filter.o" \
"CMakeFiles/Lab_5_6.dir/main.o" \
"CMakeFiles/Lab_5_6.dir/Repo.o" \
"CMakeFiles/Lab_5_6.dir/Tutorial.o" \
"CMakeFiles/Lab_5_6.dir/UI.o" \
"CMakeFiles/Lab_5_6.dir/Watchlist.o"

# External object files for target Lab_5_6
Lab_5_6_EXTERNAL_OBJECTS =

Lab_5_6: CMakeFiles/Lab_5_6.dir/Controller.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/DynamicArray.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/Filter.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/main.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/Repo.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/Tutorial.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/UI.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/Watchlist.o
Lab_5_6: CMakeFiles/Lab_5_6.dir/build.make
Lab_5_6: CMakeFiles/Lab_5_6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Lab_5_6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab_5_6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_5_6.dir/build: Lab_5_6

.PHONY : CMakeFiles/Lab_5_6.dir/build

CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/Controller.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/DynamicArray.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/Filter.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/main.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/Repo.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/Tutorial.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/UI.o.requires
CMakeFiles/Lab_5_6.dir/requires: CMakeFiles/Lab_5_6.dir/Watchlist.o.requires

.PHONY : CMakeFiles/Lab_5_6.dir/requires

CMakeFiles/Lab_5_6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab_5_6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab_5_6.dir/clean

CMakeFiles/Lab_5_6.dir/depend:
	cd "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6" "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6" "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug" "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug" "/Users/adrianflorea/Codes/C++/OOP/Lab 5-6/Lab 5-6/Lab 5-6/cmake-build-debug/CMakeFiles/Lab_5_6.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_5_6.dir/depend

