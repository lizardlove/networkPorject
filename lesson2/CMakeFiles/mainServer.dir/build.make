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
CMAKE_SOURCE_DIR = /root/networkProject/lesson2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/networkProject/lesson2

# Include any dependencies generated for this target.
include CMakeFiles/mainServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainServer.dir/flags.make

CMakeFiles/mainServer.dir/mainServer.cpp.o: CMakeFiles/mainServer.dir/flags.make
CMakeFiles/mainServer.dir/mainServer.cpp.o: mainServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/networkProject/lesson2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainServer.dir/mainServer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainServer.dir/mainServer.cpp.o -c /root/networkProject/lesson2/mainServer.cpp

CMakeFiles/mainServer.dir/mainServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainServer.dir/mainServer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/networkProject/lesson2/mainServer.cpp > CMakeFiles/mainServer.dir/mainServer.cpp.i

CMakeFiles/mainServer.dir/mainServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainServer.dir/mainServer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/networkProject/lesson2/mainServer.cpp -o CMakeFiles/mainServer.dir/mainServer.cpp.s

CMakeFiles/mainServer.dir/mainServer.cpp.o.requires:

.PHONY : CMakeFiles/mainServer.dir/mainServer.cpp.o.requires

CMakeFiles/mainServer.dir/mainServer.cpp.o.provides: CMakeFiles/mainServer.dir/mainServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/mainServer.dir/build.make CMakeFiles/mainServer.dir/mainServer.cpp.o.provides.build
.PHONY : CMakeFiles/mainServer.dir/mainServer.cpp.o.provides

CMakeFiles/mainServer.dir/mainServer.cpp.o.provides.build: CMakeFiles/mainServer.dir/mainServer.cpp.o


CMakeFiles/mainServer.dir/BaseSocket.cpp.o: CMakeFiles/mainServer.dir/flags.make
CMakeFiles/mainServer.dir/BaseSocket.cpp.o: BaseSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/networkProject/lesson2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mainServer.dir/BaseSocket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainServer.dir/BaseSocket.cpp.o -c /root/networkProject/lesson2/BaseSocket.cpp

CMakeFiles/mainServer.dir/BaseSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainServer.dir/BaseSocket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/networkProject/lesson2/BaseSocket.cpp > CMakeFiles/mainServer.dir/BaseSocket.cpp.i

CMakeFiles/mainServer.dir/BaseSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainServer.dir/BaseSocket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/networkProject/lesson2/BaseSocket.cpp -o CMakeFiles/mainServer.dir/BaseSocket.cpp.s

CMakeFiles/mainServer.dir/BaseSocket.cpp.o.requires:

.PHONY : CMakeFiles/mainServer.dir/BaseSocket.cpp.o.requires

CMakeFiles/mainServer.dir/BaseSocket.cpp.o.provides: CMakeFiles/mainServer.dir/BaseSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/mainServer.dir/build.make CMakeFiles/mainServer.dir/BaseSocket.cpp.o.provides.build
.PHONY : CMakeFiles/mainServer.dir/BaseSocket.cpp.o.provides

CMakeFiles/mainServer.dir/BaseSocket.cpp.o.provides.build: CMakeFiles/mainServer.dir/BaseSocket.cpp.o


CMakeFiles/mainServer.dir/Addr.cpp.o: CMakeFiles/mainServer.dir/flags.make
CMakeFiles/mainServer.dir/Addr.cpp.o: Addr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/networkProject/lesson2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mainServer.dir/Addr.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainServer.dir/Addr.cpp.o -c /root/networkProject/lesson2/Addr.cpp

CMakeFiles/mainServer.dir/Addr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainServer.dir/Addr.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/networkProject/lesson2/Addr.cpp > CMakeFiles/mainServer.dir/Addr.cpp.i

CMakeFiles/mainServer.dir/Addr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainServer.dir/Addr.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/networkProject/lesson2/Addr.cpp -o CMakeFiles/mainServer.dir/Addr.cpp.s

CMakeFiles/mainServer.dir/Addr.cpp.o.requires:

.PHONY : CMakeFiles/mainServer.dir/Addr.cpp.o.requires

CMakeFiles/mainServer.dir/Addr.cpp.o.provides: CMakeFiles/mainServer.dir/Addr.cpp.o.requires
	$(MAKE) -f CMakeFiles/mainServer.dir/build.make CMakeFiles/mainServer.dir/Addr.cpp.o.provides.build
.PHONY : CMakeFiles/mainServer.dir/Addr.cpp.o.provides

CMakeFiles/mainServer.dir/Addr.cpp.o.provides.build: CMakeFiles/mainServer.dir/Addr.cpp.o


# Object files for target mainServer
mainServer_OBJECTS = \
"CMakeFiles/mainServer.dir/mainServer.cpp.o" \
"CMakeFiles/mainServer.dir/BaseSocket.cpp.o" \
"CMakeFiles/mainServer.dir/Addr.cpp.o"

# External object files for target mainServer
mainServer_EXTERNAL_OBJECTS =

mainServer: CMakeFiles/mainServer.dir/mainServer.cpp.o
mainServer: CMakeFiles/mainServer.dir/BaseSocket.cpp.o
mainServer: CMakeFiles/mainServer.dir/Addr.cpp.o
mainServer: CMakeFiles/mainServer.dir/build.make
mainServer: CMakeFiles/mainServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/networkProject/lesson2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mainServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainServer.dir/build: mainServer

.PHONY : CMakeFiles/mainServer.dir/build

CMakeFiles/mainServer.dir/requires: CMakeFiles/mainServer.dir/mainServer.cpp.o.requires
CMakeFiles/mainServer.dir/requires: CMakeFiles/mainServer.dir/BaseSocket.cpp.o.requires
CMakeFiles/mainServer.dir/requires: CMakeFiles/mainServer.dir/Addr.cpp.o.requires

.PHONY : CMakeFiles/mainServer.dir/requires

CMakeFiles/mainServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainServer.dir/clean

CMakeFiles/mainServer.dir/depend:
	cd /root/networkProject/lesson2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/networkProject/lesson2 /root/networkProject/lesson2 /root/networkProject/lesson2 /root/networkProject/lesson2 /root/networkProject/lesson2/CMakeFiles/mainServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainServer.dir/depend

