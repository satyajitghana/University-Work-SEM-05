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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab05.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab05.dir/flags.make

CMakeFiles/Lab05.dir/main.cpp.o: CMakeFiles/Lab05.dir/flags.make
CMakeFiles/Lab05.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab05.dir/main.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab05.dir/main.cpp.o -c /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/main.cpp

CMakeFiles/Lab05.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab05.dir/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/main.cpp > CMakeFiles/Lab05.dir/main.cpp.i

CMakeFiles/Lab05.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab05.dir/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/main.cpp -o CMakeFiles/Lab05.dir/main.cpp.s

CMakeFiles/Lab05.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lab05.dir/main.cpp.o.requires

CMakeFiles/Lab05.dir/main.cpp.o.provides: CMakeFiles/Lab05.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab05.dir/build.make CMakeFiles/Lab05.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lab05.dir/main.cpp.o.provides

CMakeFiles/Lab05.dir/main.cpp.o.provides.build: CMakeFiles/Lab05.dir/main.cpp.o


# Object files for target Lab05
Lab05_OBJECTS = \
"CMakeFiles/Lab05.dir/main.cpp.o"

# External object files for target Lab05
Lab05_EXTERNAL_OBJECTS =

Lab05: CMakeFiles/Lab05.dir/main.cpp.o
Lab05: CMakeFiles/Lab05.dir/build.make
Lab05: CMakeFiles/Lab05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab05"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab05.dir/build: Lab05

.PHONY : CMakeFiles/Lab05.dir/build

CMakeFiles/Lab05.dir/requires: CMakeFiles/Lab05.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lab05.dir/requires

CMakeFiles/Lab05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab05.dir/clean

CMakeFiles/Lab05.dir/depend:
	cd /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05 /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05 /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build /mnt/d/University-Work/University-Work-SEM-05/CN-Lab/Lab05/build/CMakeFiles/Lab05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab05.dir/depend

