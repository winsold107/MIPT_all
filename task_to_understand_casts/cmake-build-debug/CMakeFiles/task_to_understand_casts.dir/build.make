# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/darin/github/bitbucket_algorythms2/task_to_understand_casts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task_to_understand_casts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task_to_understand_casts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task_to_understand_casts.dir/flags.make

CMakeFiles/task_to_understand_casts.dir/main.cpp.o: CMakeFiles/task_to_understand_casts.dir/flags.make
CMakeFiles/task_to_understand_casts.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task_to_understand_casts.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_to_understand_casts.dir/main.cpp.o -c /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/main.cpp

CMakeFiles/task_to_understand_casts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_to_understand_casts.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/main.cpp > CMakeFiles/task_to_understand_casts.dir/main.cpp.i

CMakeFiles/task_to_understand_casts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_to_understand_casts.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/main.cpp -o CMakeFiles/task_to_understand_casts.dir/main.cpp.s

CMakeFiles/task_to_understand_casts.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/task_to_understand_casts.dir/main.cpp.o.requires

CMakeFiles/task_to_understand_casts.dir/main.cpp.o.provides: CMakeFiles/task_to_understand_casts.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/task_to_understand_casts.dir/build.make CMakeFiles/task_to_understand_casts.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/task_to_understand_casts.dir/main.cpp.o.provides

CMakeFiles/task_to_understand_casts.dir/main.cpp.o.provides.build: CMakeFiles/task_to_understand_casts.dir/main.cpp.o


# Object files for target task_to_understand_casts
task_to_understand_casts_OBJECTS = \
"CMakeFiles/task_to_understand_casts.dir/main.cpp.o"

# External object files for target task_to_understand_casts
task_to_understand_casts_EXTERNAL_OBJECTS =

task_to_understand_casts: CMakeFiles/task_to_understand_casts.dir/main.cpp.o
task_to_understand_casts: CMakeFiles/task_to_understand_casts.dir/build.make
task_to_understand_casts: CMakeFiles/task_to_understand_casts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task_to_understand_casts"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_to_understand_casts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task_to_understand_casts.dir/build: task_to_understand_casts

.PHONY : CMakeFiles/task_to_understand_casts.dir/build

CMakeFiles/task_to_understand_casts.dir/requires: CMakeFiles/task_to_understand_casts.dir/main.cpp.o.requires

.PHONY : CMakeFiles/task_to_understand_casts.dir/requires

CMakeFiles/task_to_understand_casts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task_to_understand_casts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task_to_understand_casts.dir/clean

CMakeFiles/task_to_understand_casts.dir/depend:
	cd /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darin/github/bitbucket_algorythms2/task_to_understand_casts /home/darin/github/bitbucket_algorythms2/task_to_understand_casts /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug /home/darin/github/bitbucket_algorythms2/task_to_understand_casts/cmake-build-debug/CMakeFiles/task_to_understand_casts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task_to_understand_casts.dir/depend

