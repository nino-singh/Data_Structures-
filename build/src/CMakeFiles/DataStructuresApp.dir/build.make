# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ninoshkasingh/gitrepos/Data_Structures-

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ninoshkasingh/gitrepos/Data_Structures-/build

# Include any dependencies generated for this target.
include src/CMakeFiles/DataStructuresApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/DataStructuresApp.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/DataStructuresApp.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/DataStructuresApp.dir/flags.make

src/CMakeFiles/DataStructuresApp.dir/main.cpp.o: src/CMakeFiles/DataStructuresApp.dir/flags.make
src/CMakeFiles/DataStructuresApp.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/DataStructuresApp.dir/main.cpp.o: src/CMakeFiles/DataStructuresApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ninoshkasingh/gitrepos/Data_Structures-/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/DataStructuresApp.dir/main.cpp.o"
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/DataStructuresApp.dir/main.cpp.o -MF CMakeFiles/DataStructuresApp.dir/main.cpp.o.d -o CMakeFiles/DataStructuresApp.dir/main.cpp.o -c /Users/ninoshkasingh/gitrepos/Data_Structures-/src/main.cpp

src/CMakeFiles/DataStructuresApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructuresApp.dir/main.cpp.i"
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ninoshkasingh/gitrepos/Data_Structures-/src/main.cpp > CMakeFiles/DataStructuresApp.dir/main.cpp.i

src/CMakeFiles/DataStructuresApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructuresApp.dir/main.cpp.s"
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ninoshkasingh/gitrepos/Data_Structures-/src/main.cpp -o CMakeFiles/DataStructuresApp.dir/main.cpp.s

# Object files for target DataStructuresApp
DataStructuresApp_OBJECTS = \
"CMakeFiles/DataStructuresApp.dir/main.cpp.o"

# External object files for target DataStructuresApp
DataStructuresApp_EXTERNAL_OBJECTS =

src/DataStructuresApp: src/CMakeFiles/DataStructuresApp.dir/main.cpp.o
src/DataStructuresApp: src/CMakeFiles/DataStructuresApp.dir/build.make
src/DataStructuresApp: src/libDataStructuresLib.a
src/DataStructuresApp: src/CMakeFiles/DataStructuresApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ninoshkasingh/gitrepos/Data_Structures-/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataStructuresApp"
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructuresApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/DataStructuresApp.dir/build: src/DataStructuresApp
.PHONY : src/CMakeFiles/DataStructuresApp.dir/build

src/CMakeFiles/DataStructuresApp.dir/clean:
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src && $(CMAKE_COMMAND) -P CMakeFiles/DataStructuresApp.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/DataStructuresApp.dir/clean

src/CMakeFiles/DataStructuresApp.dir/depend:
	cd /Users/ninoshkasingh/gitrepos/Data_Structures-/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ninoshkasingh/gitrepos/Data_Structures- /Users/ninoshkasingh/gitrepos/Data_Structures-/src /Users/ninoshkasingh/gitrepos/Data_Structures-/build /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src /Users/ninoshkasingh/gitrepos/Data_Structures-/build/src/CMakeFiles/DataStructuresApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/DataStructuresApp.dir/depend

