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
CMAKE_SOURCE_DIR = /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build

# Include any dependencies generated for this target.
include app/CMakeFiles/ccount.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/ccount.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/ccount.dir/flags.make

app/CMakeFiles/ccount.dir/main.cpp.o: app/CMakeFiles/ccount.dir/flags.make
app/CMakeFiles/ccount.dir/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/ccount.dir/main.cpp.o"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ccount.dir/main.cpp.o -c /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/main.cpp

app/CMakeFiles/ccount.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccount.dir/main.cpp.i"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/main.cpp > CMakeFiles/ccount.dir/main.cpp.i

app/CMakeFiles/ccount.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccount.dir/main.cpp.s"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/main.cpp -o CMakeFiles/ccount.dir/main.cpp.s

app/CMakeFiles/ccount.dir/file_ops.cpp.o: app/CMakeFiles/ccount.dir/flags.make
app/CMakeFiles/ccount.dir/file_ops.cpp.o: ../app/file_ops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/CMakeFiles/ccount.dir/file_ops.cpp.o"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ccount.dir/file_ops.cpp.o -c /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/file_ops.cpp

app/CMakeFiles/ccount.dir/file_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccount.dir/file_ops.cpp.i"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/file_ops.cpp > CMakeFiles/ccount.dir/file_ops.cpp.i

app/CMakeFiles/ccount.dir/file_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccount.dir/file_ops.cpp.s"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/file_ops.cpp -o CMakeFiles/ccount.dir/file_ops.cpp.s

app/CMakeFiles/ccount.dir/threader.cpp.o: app/CMakeFiles/ccount.dir/flags.make
app/CMakeFiles/ccount.dir/threader.cpp.o: ../app/threader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object app/CMakeFiles/ccount.dir/threader.cpp.o"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ccount.dir/threader.cpp.o -c /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/threader.cpp

app/CMakeFiles/ccount.dir/threader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccount.dir/threader.cpp.i"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/threader.cpp > CMakeFiles/ccount.dir/threader.cpp.i

app/CMakeFiles/ccount.dir/threader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccount.dir/threader.cpp.s"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app/threader.cpp -o CMakeFiles/ccount.dir/threader.cpp.s

# Object files for target ccount
ccount_OBJECTS = \
"CMakeFiles/ccount.dir/main.cpp.o" \
"CMakeFiles/ccount.dir/file_ops.cpp.o" \
"CMakeFiles/ccount.dir/threader.cpp.o"

# External object files for target ccount
ccount_EXTERNAL_OBJECTS =

app/ccount: app/CMakeFiles/ccount.dir/main.cpp.o
app/ccount: app/CMakeFiles/ccount.dir/file_ops.cpp.o
app/ccount: app/CMakeFiles/ccount.dir/threader.cpp.o
app/ccount: app/CMakeFiles/ccount.dir/build.make
app/ccount: app/CMakeFiles/ccount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ccount"
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ccount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/ccount.dir/build: app/ccount

.PHONY : app/CMakeFiles/ccount.dir/build

app/CMakeFiles/ccount.dir/clean:
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app && $(CMAKE_COMMAND) -P CMakeFiles/ccount.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/ccount.dir/clean

app/CMakeFiles/ccount.dir/depend:
	cd /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/app /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app /mnt/data/University-Work-SEM-05/Assignment-SEM05-2019/OS/ccount/build/app/CMakeFiles/ccount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/ccount.dir/depend

