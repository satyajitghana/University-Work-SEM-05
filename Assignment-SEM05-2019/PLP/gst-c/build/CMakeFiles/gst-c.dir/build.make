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
CMAKE_SOURCE_DIR = /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build

# Include any dependencies generated for this target.
include CMakeFiles/gst-c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gst-c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gst-c.dir/flags.make

CMakeFiles/gst-c.dir/main.c.o: CMakeFiles/gst-c.dir/flags.make
CMakeFiles/gst-c.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gst-c.dir/main.c.o"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gst-c.dir/main.c.o   -c /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/main.c

CMakeFiles/gst-c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gst-c.dir/main.c.i"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/main.c > CMakeFiles/gst-c.dir/main.c.i

CMakeFiles/gst-c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gst-c.dir/main.c.s"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/main.c -o CMakeFiles/gst-c.dir/main.c.s

CMakeFiles/gst-c.dir/main.c.o.requires:

.PHONY : CMakeFiles/gst-c.dir/main.c.o.requires

CMakeFiles/gst-c.dir/main.c.o.provides: CMakeFiles/gst-c.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/gst-c.dir/build.make CMakeFiles/gst-c.dir/main.c.o.provides.build
.PHONY : CMakeFiles/gst-c.dir/main.c.o.provides

CMakeFiles/gst-c.dir/main.c.o.provides.build: CMakeFiles/gst-c.dir/main.c.o


CMakeFiles/gst-c.dir/array_list.c.o: CMakeFiles/gst-c.dir/flags.make
CMakeFiles/gst-c.dir/array_list.c.o: ../array_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gst-c.dir/array_list.c.o"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gst-c.dir/array_list.c.o   -c /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/array_list.c

CMakeFiles/gst-c.dir/array_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gst-c.dir/array_list.c.i"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/array_list.c > CMakeFiles/gst-c.dir/array_list.c.i

CMakeFiles/gst-c.dir/array_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gst-c.dir/array_list.c.s"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/array_list.c -o CMakeFiles/gst-c.dir/array_list.c.s

CMakeFiles/gst-c.dir/array_list.c.o.requires:

.PHONY : CMakeFiles/gst-c.dir/array_list.c.o.requires

CMakeFiles/gst-c.dir/array_list.c.o.provides: CMakeFiles/gst-c.dir/array_list.c.o.requires
	$(MAKE) -f CMakeFiles/gst-c.dir/build.make CMakeFiles/gst-c.dir/array_list.c.o.provides.build
.PHONY : CMakeFiles/gst-c.dir/array_list.c.o.provides

CMakeFiles/gst-c.dir/array_list.c.o.provides.build: CMakeFiles/gst-c.dir/array_list.c.o


CMakeFiles/gst-c.dir/gst_item.c.o: CMakeFiles/gst-c.dir/flags.make
CMakeFiles/gst-c.dir/gst_item.c.o: ../gst_item.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gst-c.dir/gst_item.c.o"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gst-c.dir/gst_item.c.o   -c /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/gst_item.c

CMakeFiles/gst-c.dir/gst_item.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gst-c.dir/gst_item.c.i"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/gst_item.c > CMakeFiles/gst-c.dir/gst_item.c.i

CMakeFiles/gst-c.dir/gst_item.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gst-c.dir/gst_item.c.s"
	/usr/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/gst_item.c -o CMakeFiles/gst-c.dir/gst_item.c.s

CMakeFiles/gst-c.dir/gst_item.c.o.requires:

.PHONY : CMakeFiles/gst-c.dir/gst_item.c.o.requires

CMakeFiles/gst-c.dir/gst_item.c.o.provides: CMakeFiles/gst-c.dir/gst_item.c.o.requires
	$(MAKE) -f CMakeFiles/gst-c.dir/build.make CMakeFiles/gst-c.dir/gst_item.c.o.provides.build
.PHONY : CMakeFiles/gst-c.dir/gst_item.c.o.provides

CMakeFiles/gst-c.dir/gst_item.c.o.provides.build: CMakeFiles/gst-c.dir/gst_item.c.o


# Object files for target gst-c
gst__c_OBJECTS = \
"CMakeFiles/gst-c.dir/main.c.o" \
"CMakeFiles/gst-c.dir/array_list.c.o" \
"CMakeFiles/gst-c.dir/gst_item.c.o"

# External object files for target gst-c
gst__c_EXTERNAL_OBJECTS =

gst-c: CMakeFiles/gst-c.dir/main.c.o
gst-c: CMakeFiles/gst-c.dir/array_list.c.o
gst-c: CMakeFiles/gst-c.dir/gst_item.c.o
gst-c: CMakeFiles/gst-c.dir/build.make
gst-c: CMakeFiles/gst-c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable gst-c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gst-c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gst-c.dir/build: gst-c

.PHONY : CMakeFiles/gst-c.dir/build

CMakeFiles/gst-c.dir/requires: CMakeFiles/gst-c.dir/main.c.o.requires
CMakeFiles/gst-c.dir/requires: CMakeFiles/gst-c.dir/array_list.c.o.requires
CMakeFiles/gst-c.dir/requires: CMakeFiles/gst-c.dir/gst_item.c.o.requires

.PHONY : CMakeFiles/gst-c.dir/requires

CMakeFiles/gst-c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gst-c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gst-c.dir/clean

CMakeFiles/gst-c.dir/depend:
	cd /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build /mnt/d/University-Work/University-Work-SEM-05/Assignment-SEM05-2019/PLP/gst-c/build/CMakeFiles/gst-c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gst-c.dir/depend

