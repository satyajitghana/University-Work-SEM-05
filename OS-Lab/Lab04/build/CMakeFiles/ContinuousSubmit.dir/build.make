# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04/build

# Utility rule file for ContinuousSubmit.

# Include the progress variables for this target.
include CMakeFiles/ContinuousSubmit.dir/progress.make

CMakeFiles/ContinuousSubmit:
	/opt/cmake/bin/ctest -D ContinuousSubmit

ContinuousSubmit: CMakeFiles/ContinuousSubmit
ContinuousSubmit: CMakeFiles/ContinuousSubmit.dir/build.make

.PHONY : ContinuousSubmit

# Rule to build all files generated by this target.
CMakeFiles/ContinuousSubmit.dir/build: ContinuousSubmit

.PHONY : CMakeFiles/ContinuousSubmit.dir/build

CMakeFiles/ContinuousSubmit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousSubmit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousSubmit.dir/clean

CMakeFiles/ContinuousSubmit.dir/depend:
	cd /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04 /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04 /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04/build /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04/build /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab04/build/CMakeFiles/ContinuousSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousSubmit.dir/depend

