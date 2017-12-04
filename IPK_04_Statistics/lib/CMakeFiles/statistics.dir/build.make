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
CMAKE_SOURCE_DIR = /home/nuar/Projects/Eclipse/IPK_04_Statistics/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nuar/Projects/Eclipse/IPK_04_Statistics

# Include any dependencies generated for this target.
include lib/CMakeFiles/statistics.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/statistics.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/statistics.dir/flags.make

lib/CMakeFiles/statistics.dir/statistics.cpp.o: lib/CMakeFiles/statistics.dir/flags.make
lib/CMakeFiles/statistics.dir/statistics.cpp.o: source/lib/statistics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nuar/Projects/Eclipse/IPK_04_Statistics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/statistics.dir/statistics.cpp.o"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/statistics.dir/statistics.cpp.o -c /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/statistics.cpp

lib/CMakeFiles/statistics.dir/statistics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/statistics.dir/statistics.cpp.i"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/statistics.cpp > CMakeFiles/statistics.dir/statistics.cpp.i

lib/CMakeFiles/statistics.dir/statistics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/statistics.dir/statistics.cpp.s"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/statistics.cpp -o CMakeFiles/statistics.dir/statistics.cpp.s

lib/CMakeFiles/statistics.dir/statistics.cpp.o.requires:

.PHONY : lib/CMakeFiles/statistics.dir/statistics.cpp.o.requires

lib/CMakeFiles/statistics.dir/statistics.cpp.o.provides: lib/CMakeFiles/statistics.dir/statistics.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/statistics.dir/build.make lib/CMakeFiles/statistics.dir/statistics.cpp.o.provides.build
.PHONY : lib/CMakeFiles/statistics.dir/statistics.cpp.o.provides

lib/CMakeFiles/statistics.dir/statistics.cpp.o.provides.build: lib/CMakeFiles/statistics.dir/statistics.cpp.o


lib/CMakeFiles/statistics.dir/io.cc.o: lib/CMakeFiles/statistics.dir/flags.make
lib/CMakeFiles/statistics.dir/io.cc.o: source/lib/io.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nuar/Projects/Eclipse/IPK_04_Statistics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/statistics.dir/io.cc.o"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/statistics.dir/io.cc.o -c /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/io.cc

lib/CMakeFiles/statistics.dir/io.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/statistics.dir/io.cc.i"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/io.cc > CMakeFiles/statistics.dir/io.cc.i

lib/CMakeFiles/statistics.dir/io.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/statistics.dir/io.cc.s"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib/io.cc -o CMakeFiles/statistics.dir/io.cc.s

lib/CMakeFiles/statistics.dir/io.cc.o.requires:

.PHONY : lib/CMakeFiles/statistics.dir/io.cc.o.requires

lib/CMakeFiles/statistics.dir/io.cc.o.provides: lib/CMakeFiles/statistics.dir/io.cc.o.requires
	$(MAKE) -f lib/CMakeFiles/statistics.dir/build.make lib/CMakeFiles/statistics.dir/io.cc.o.provides.build
.PHONY : lib/CMakeFiles/statistics.dir/io.cc.o.provides

lib/CMakeFiles/statistics.dir/io.cc.o.provides.build: lib/CMakeFiles/statistics.dir/io.cc.o


# Object files for target statistics
statistics_OBJECTS = \
"CMakeFiles/statistics.dir/statistics.cpp.o" \
"CMakeFiles/statistics.dir/io.cc.o"

# External object files for target statistics
statistics_EXTERNAL_OBJECTS =

lib/libstatistics.a: lib/CMakeFiles/statistics.dir/statistics.cpp.o
lib/libstatistics.a: lib/CMakeFiles/statistics.dir/io.cc.o
lib/libstatistics.a: lib/CMakeFiles/statistics.dir/build.make
lib/libstatistics.a: lib/CMakeFiles/statistics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nuar/Projects/Eclipse/IPK_04_Statistics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libstatistics.a"
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && $(CMAKE_COMMAND) -P CMakeFiles/statistics.dir/cmake_clean_target.cmake
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/statistics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/statistics.dir/build: lib/libstatistics.a

.PHONY : lib/CMakeFiles/statistics.dir/build

lib/CMakeFiles/statistics.dir/requires: lib/CMakeFiles/statistics.dir/statistics.cpp.o.requires
lib/CMakeFiles/statistics.dir/requires: lib/CMakeFiles/statistics.dir/io.cc.o.requires

.PHONY : lib/CMakeFiles/statistics.dir/requires

lib/CMakeFiles/statistics.dir/clean:
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib && $(CMAKE_COMMAND) -P CMakeFiles/statistics.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/statistics.dir/clean

lib/CMakeFiles/statistics.dir/depend:
	cd /home/nuar/Projects/Eclipse/IPK_04_Statistics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nuar/Projects/Eclipse/IPK_04_Statistics/source /home/nuar/Projects/Eclipse/IPK_04_Statistics/source/lib /home/nuar/Projects/Eclipse/IPK_04_Statistics /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib /home/nuar/Projects/Eclipse/IPK_04_Statistics/lib/CMakeFiles/statistics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/statistics.dir/depend

