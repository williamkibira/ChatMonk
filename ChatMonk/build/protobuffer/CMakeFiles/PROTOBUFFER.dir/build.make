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
include protobuffer/CMakeFiles/PROTOBUFFER.dir/depend.make

# Include the progress variables for this target.
include protobuffer/CMakeFiles/PROTOBUFFER.dir/progress.make

# Include the compile flags for this target's objects.
include protobuffer/CMakeFiles/PROTOBUFFER.dir/flags.make

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o: protobuffer/CMakeFiles/PROTOBUFFER.dir/flags.make
protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o: ../protobuffer/chat_monk.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o -c /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/protobuffer/chat_monk.pb.cc

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.i"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/protobuffer/chat_monk.pb.cc > CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.i

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.s"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/protobuffer/chat_monk.pb.cc -o CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.s

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.requires:
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.requires

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.provides: protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.requires
	$(MAKE) -f protobuffer/CMakeFiles/PROTOBUFFER.dir/build.make protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.provides.build
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.provides

protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.provides.build: protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o

# Object files for target PROTOBUFFER
PROTOBUFFER_OBJECTS = \
"CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o"

# External object files for target PROTOBUFFER
PROTOBUFFER_EXTERNAL_OBJECTS =

protobuffer/libPROTOBUFFER.a: protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o
protobuffer/libPROTOBUFFER.a: protobuffer/CMakeFiles/PROTOBUFFER.dir/build.make
protobuffer/libPROTOBUFFER.a: protobuffer/CMakeFiles/PROTOBUFFER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libPROTOBUFFER.a"
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && $(CMAKE_COMMAND) -P CMakeFiles/PROTOBUFFER.dir/cmake_clean_target.cmake
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PROTOBUFFER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
protobuffer/CMakeFiles/PROTOBUFFER.dir/build: protobuffer/libPROTOBUFFER.a
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/build

protobuffer/CMakeFiles/PROTOBUFFER.dir/requires: protobuffer/CMakeFiles/PROTOBUFFER.dir/chat_monk.pb.cc.o.requires
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/requires

protobuffer/CMakeFiles/PROTOBUFFER.dir/clean:
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer && $(CMAKE_COMMAND) -P CMakeFiles/PROTOBUFFER.dir/cmake_clean.cmake
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/clean

protobuffer/CMakeFiles/PROTOBUFFER.dir/depend:
	cd /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/protobuffer /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer /home/william/Projects/CPP_Projects/CHAT_MONK/Chatmonk/ChatMonk/build/protobuffer/CMakeFiles/PROTOBUFFER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : protobuffer/CMakeFiles/PROTOBUFFER.dir/depend

