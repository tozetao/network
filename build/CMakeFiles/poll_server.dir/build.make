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
CMAKE_SOURCE_DIR = /home/cprojects/network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cprojects/network/build

# Include any dependencies generated for this target.
include CMakeFiles/poll_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/poll_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poll_server.dir/flags.make

CMakeFiles/poll_server.dir/poll_server.c.o: CMakeFiles/poll_server.dir/flags.make
CMakeFiles/poll_server.dir/poll_server.c.o: ../poll_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cprojects/network/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/poll_server.dir/poll_server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/poll_server.dir/poll_server.c.o   -c /home/cprojects/network/poll_server.c

CMakeFiles/poll_server.dir/poll_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/poll_server.dir/poll_server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cprojects/network/poll_server.c > CMakeFiles/poll_server.dir/poll_server.c.i

CMakeFiles/poll_server.dir/poll_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/poll_server.dir/poll_server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cprojects/network/poll_server.c -o CMakeFiles/poll_server.dir/poll_server.c.s

CMakeFiles/poll_server.dir/poll_server.c.o.requires:

.PHONY : CMakeFiles/poll_server.dir/poll_server.c.o.requires

CMakeFiles/poll_server.dir/poll_server.c.o.provides: CMakeFiles/poll_server.dir/poll_server.c.o.requires
	$(MAKE) -f CMakeFiles/poll_server.dir/build.make CMakeFiles/poll_server.dir/poll_server.c.o.provides.build
.PHONY : CMakeFiles/poll_server.dir/poll_server.c.o.provides

CMakeFiles/poll_server.dir/poll_server.c.o.provides.build: CMakeFiles/poll_server.dir/poll_server.c.o


# Object files for target poll_server
poll_server_OBJECTS = \
"CMakeFiles/poll_server.dir/poll_server.c.o"

# External object files for target poll_server
poll_server_EXTERNAL_OBJECTS =

poll_server: CMakeFiles/poll_server.dir/poll_server.c.o
poll_server: CMakeFiles/poll_server.dir/build.make
poll_server: libnet_lib.a
poll_server: CMakeFiles/poll_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cprojects/network/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable poll_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/poll_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poll_server.dir/build: poll_server

.PHONY : CMakeFiles/poll_server.dir/build

CMakeFiles/poll_server.dir/requires: CMakeFiles/poll_server.dir/poll_server.c.o.requires

.PHONY : CMakeFiles/poll_server.dir/requires

CMakeFiles/poll_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/poll_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/poll_server.dir/clean

CMakeFiles/poll_server.dir/depend:
	cd /home/cprojects/network/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cprojects/network /home/cprojects/network /home/cprojects/network/build /home/cprojects/network/build /home/cprojects/network/build/CMakeFiles/poll_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/poll_server.dir/depend
