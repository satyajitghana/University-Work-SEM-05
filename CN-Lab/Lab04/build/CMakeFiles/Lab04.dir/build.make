# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /mnt/data/University-Work-SEM-05/CN-Lab/Lab04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab04.dir/flags.make

CMakeFiles/Lab04.dir/main.cpp.o: CMakeFiles/Lab04.dir/flags.make
CMakeFiles/Lab04.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab04.dir/main.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab04.dir/main.cpp.o -c /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/main.cpp

CMakeFiles/Lab04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab04.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/main.cpp > CMakeFiles/Lab04.dir/main.cpp.i

CMakeFiles/Lab04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab04.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/main.cpp -o CMakeFiles/Lab04.dir/main.cpp.s

CMakeFiles/Lab04.dir/graph.cpp.o: CMakeFiles/Lab04.dir/flags.make
CMakeFiles/Lab04.dir/graph.cpp.o: ../graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab04.dir/graph.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab04.dir/graph.cpp.o -c /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/graph.cpp

CMakeFiles/Lab04.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab04.dir/graph.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/graph.cpp > CMakeFiles/Lab04.dir/graph.cpp.i

CMakeFiles/Lab04.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab04.dir/graph.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/graph.cpp -o CMakeFiles/Lab04.dir/graph.cpp.s

CMakeFiles/Lab04.dir/routing_table.cpp.o: CMakeFiles/Lab04.dir/flags.make
CMakeFiles/Lab04.dir/routing_table.cpp.o: ../routing_table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab04.dir/routing_table.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab04.dir/routing_table.cpp.o -c /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/routing_table.cpp

CMakeFiles/Lab04.dir/routing_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab04.dir/routing_table.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/routing_table.cpp > CMakeFiles/Lab04.dir/routing_table.cpp.i

CMakeFiles/Lab04.dir/routing_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab04.dir/routing_table.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/routing_table.cpp -o CMakeFiles/Lab04.dir/routing_table.cpp.s

# Object files for target Lab04
Lab04_OBJECTS = \
"CMakeFiles/Lab04.dir/main.cpp.o" \
"CMakeFiles/Lab04.dir/graph.cpp.o" \
"CMakeFiles/Lab04.dir/routing_table.cpp.o"

# External object files for target Lab04
Lab04_EXTERNAL_OBJECTS =

Lab04: CMakeFiles/Lab04.dir/main.cpp.o
Lab04: CMakeFiles/Lab04.dir/graph.cpp.o
Lab04: CMakeFiles/Lab04.dir/routing_table.cpp.o
Lab04: CMakeFiles/Lab04.dir/build.make
Lab04: CMakeFiles/Lab04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Lab04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab04.dir/build: Lab04

.PHONY : CMakeFiles/Lab04.dir/build

CMakeFiles/Lab04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab04.dir/clean

CMakeFiles/Lab04.dir/depend:
	cd /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/data/University-Work-SEM-05/CN-Lab/Lab04 /mnt/data/University-Work-SEM-05/CN-Lab/Lab04 /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build /mnt/data/University-Work-SEM-05/CN-Lab/Lab04/build/CMakeFiles/Lab04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab04.dir/depend

