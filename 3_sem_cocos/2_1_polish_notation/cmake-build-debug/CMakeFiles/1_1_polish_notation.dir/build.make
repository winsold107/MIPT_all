# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/darin/programs/jetbrains/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/darin/programs/jetbrains/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_1_polish_notation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_1_polish_notation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_1_polish_notation.dir/flags.make

CMakeFiles/1_1_polish_notation.dir/main.c.o: CMakeFiles/1_1_polish_notation.dir/flags.make
CMakeFiles/1_1_polish_notation.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/1_1_polish_notation.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/1_1_polish_notation.dir/main.c.o   -c /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/main.c

CMakeFiles/1_1_polish_notation.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/1_1_polish_notation.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/main.c > CMakeFiles/1_1_polish_notation.dir/main.c.i

CMakeFiles/1_1_polish_notation.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/1_1_polish_notation.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/main.c -o CMakeFiles/1_1_polish_notation.dir/main.c.s

CMakeFiles/1_1_polish_notation.dir/main.c.o.requires:

.PHONY : CMakeFiles/1_1_polish_notation.dir/main.c.o.requires

CMakeFiles/1_1_polish_notation.dir/main.c.o.provides: CMakeFiles/1_1_polish_notation.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/1_1_polish_notation.dir/build.make CMakeFiles/1_1_polish_notation.dir/main.c.o.provides.build
.PHONY : CMakeFiles/1_1_polish_notation.dir/main.c.o.provides

CMakeFiles/1_1_polish_notation.dir/main.c.o.provides.build: CMakeFiles/1_1_polish_notation.dir/main.c.o


# Object files for target 1_1_polish_notation
1_1_polish_notation_OBJECTS = \
"CMakeFiles/1_1_polish_notation.dir/main.c.o"

# External object files for target 1_1_polish_notation
1_1_polish_notation_EXTERNAL_OBJECTS =

1_1_polish_notation: CMakeFiles/1_1_polish_notation.dir/main.c.o
1_1_polish_notation: CMakeFiles/1_1_polish_notation.dir/build.make
1_1_polish_notation: CMakeFiles/1_1_polish_notation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 1_1_polish_notation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_1_polish_notation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_1_polish_notation.dir/build: 1_1_polish_notation

.PHONY : CMakeFiles/1_1_polish_notation.dir/build

CMakeFiles/1_1_polish_notation.dir/requires: CMakeFiles/1_1_polish_notation.dir/main.c.o.requires

.PHONY : CMakeFiles/1_1_polish_notation.dir/requires

CMakeFiles/1_1_polish_notation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_1_polish_notation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_1_polish_notation.dir/clean

CMakeFiles/1_1_polish_notation.dir/depend:
	cd /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug /home/darin/github/MIPT/3_sem_cocos/1_1_polish_notation/cmake-build-debug/CMakeFiles/1_1_polish_notation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1_1_polish_notation.dir/depend

