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
CMAKE_SOURCE_DIR = /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab06Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab06Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab06Client.dir/flags.make

CMakeFiles/Lab06Client.dir/main.cpp.o: CMakeFiles/Lab06Client.dir/flags.make
CMakeFiles/Lab06Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab06Client.dir/main.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab06Client.dir/main.cpp.o -c /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/main.cpp

CMakeFiles/Lab06Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab06Client.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/main.cpp > CMakeFiles/Lab06Client.dir/main.cpp.i

CMakeFiles/Lab06Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab06Client.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/main.cpp -o CMakeFiles/Lab06Client.dir/main.cpp.s

# Object files for target Lab06Client
Lab06Client_OBJECTS = \
"CMakeFiles/Lab06Client.dir/main.cpp.o"

# External object files for target Lab06Client
Lab06Client_EXTERNAL_OBJECTS =

Lab06Client: CMakeFiles/Lab06Client.dir/main.cpp.o
Lab06Client: CMakeFiles/Lab06Client.dir/build.make
Lab06Client: CMakeFiles/Lab06Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab06Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab06Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab06Client.dir/build: Lab06Client

.PHONY : CMakeFiles/Lab06Client.dir/build

CMakeFiles/Lab06Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab06Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab06Client.dir/clean

CMakeFiles/Lab06Client.dir/depend:
	cd /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build /mnt/data/University-Work-SEM-05/CN-Lab/Lab07/Lab06Client/build/CMakeFiles/Lab06Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab06Client.dir/depend

