# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build

# Include any dependencies generated for this target.
include network_handler/CMakeFiles/NETWORK_HANDLER.dir/depend.make

# Include the progress variables for this target.
include network_handler/CMakeFiles/NETWORK_HANDLER.dir/progress.make

# Include the compile flags for this target's objects.
include network_handler/CMakeFiles/NETWORK_HANDLER.dir/flags.make

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o: network_handler/CMakeFiles/NETWORK_HANDLER.dir/flags.make
network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o: ../network_handler/networkhandler.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o -c /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/network_handler/networkhandler.cpp

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.i"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/network_handler/networkhandler.cpp > CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.i

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.s"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/network_handler/networkhandler.cpp -o CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.s

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.requires:
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.requires

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.provides: network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.requires
	$(MAKE) -f network_handler/CMakeFiles/NETWORK_HANDLER.dir/build.make network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.provides.build
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.provides

network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.provides.build: network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o

# Object files for target NETWORK_HANDLER
NETWORK_HANDLER_OBJECTS = \
"CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o"

# External object files for target NETWORK_HANDLER
NETWORK_HANDLER_EXTERNAL_OBJECTS =

network_handler/libNETWORK_HANDLER.a: network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o
network_handler/libNETWORK_HANDLER.a: network_handler/CMakeFiles/NETWORK_HANDLER.dir/build.make
network_handler/libNETWORK_HANDLER.a: network_handler/CMakeFiles/NETWORK_HANDLER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libNETWORK_HANDLER.a"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && $(CMAKE_COMMAND) -P CMakeFiles/NETWORK_HANDLER.dir/cmake_clean_target.cmake
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NETWORK_HANDLER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
network_handler/CMakeFiles/NETWORK_HANDLER.dir/build: network_handler/libNETWORK_HANDLER.a
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/build

network_handler/CMakeFiles/NETWORK_HANDLER.dir/requires: network_handler/CMakeFiles/NETWORK_HANDLER.dir/networkhandler.cpp.o.requires
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/requires

network_handler/CMakeFiles/NETWORK_HANDLER.dir/clean:
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler && $(CMAKE_COMMAND) -P CMakeFiles/NETWORK_HANDLER.dir/cmake_clean.cmake
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/clean

network_handler/CMakeFiles/NETWORK_HANDLER.dir/depend:
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/network_handler /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/network_handler/CMakeFiles/NETWORK_HANDLER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : network_handler/CMakeFiles/NETWORK_HANDLER.dir/depend

