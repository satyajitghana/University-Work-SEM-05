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
CMAKE_SOURCE_DIR = /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab07.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab07.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab07.dir/flags.make

CMakeFiles/Lab07.dir/main.cpp.o: CMakeFiles/Lab07.dir/flags.make
CMakeFiles/Lab07.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab07.dir/main.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab07.dir/main.cpp.o -c /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/main.cpp

CMakeFiles/Lab07.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab07.dir/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/main.cpp > CMakeFiles/Lab07.dir/main.cpp.i

CMakeFiles/Lab07.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab07.dir/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/main.cpp -o CMakeFiles/Lab07.dir/main.cpp.s

CMakeFiles/Lab07.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lab07.dir/main.cpp.o.requires

CMakeFiles/Lab07.dir/main.cpp.o.provides: CMakeFiles/Lab07.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab07.dir/build.make CMakeFiles/Lab07.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lab07.dir/main.cpp.o.provides

CMakeFiles/Lab07.dir/main.cpp.o.provides.build: CMakeFiles/Lab07.dir/main.cpp.o


# Object files for target Lab07
Lab07_OBJECTS = \
"CMakeFiles/Lab07.dir/main.cpp.o"

# External object files for target Lab07
Lab07_EXTERNAL_OBJECTS =

Lab07: CMakeFiles/Lab07.dir/main.cpp.o
Lab07: CMakeFiles/Lab07.dir/build.make
Lab07: CMakeFiles/Lab07.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab07"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab07.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab07.dir/build: Lab07

.PHONY : CMakeFiles/Lab07.dir/build

CMakeFiles/Lab07.dir/requires: CMakeFiles/Lab07.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lab07.dir/requires

CMakeFiles/Lab07.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab07.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab07.dir/clean

CMakeFiles/Lab07.dir/depend:
	cd /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07 /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07 /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build /mnt/d/University-Work/University-Work-SEM-05/OS-Lab/Lab07/build/CMakeFiles/Lab07.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab07.dir/depend

