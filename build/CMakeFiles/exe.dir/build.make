# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/void/Documents/CODES/TheProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/void/Documents/CODES/TheProject/build

# Include any dependencies generated for this target.
include CMakeFiles/exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exe.dir/flags.make

CMakeFiles/exe.dir/src/main.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/exe.dir/src/main.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exe.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/main.cpp.o -MF CMakeFiles/exe.dir/src/main.cpp.o.d -o CMakeFiles/exe.dir/src/main.cpp.o -c /home/void/Documents/CODES/TheProject/src/main.cpp

CMakeFiles/exe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/main.cpp > CMakeFiles/exe.dir/src/main.cpp.i

CMakeFiles/exe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/main.cpp -o CMakeFiles/exe.dir/src/main.cpp.s

CMakeFiles/exe.dir/src/tile.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/tile.cpp.o: ../src/tile.cpp
CMakeFiles/exe.dir/src/tile.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exe.dir/src/tile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/tile.cpp.o -MF CMakeFiles/exe.dir/src/tile.cpp.o.d -o CMakeFiles/exe.dir/src/tile.cpp.o -c /home/void/Documents/CODES/TheProject/src/tile.cpp

CMakeFiles/exe.dir/src/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/tile.cpp > CMakeFiles/exe.dir/src/tile.cpp.i

CMakeFiles/exe.dir/src/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/tile.cpp -o CMakeFiles/exe.dir/src/tile.cpp.s

CMakeFiles/exe.dir/src/map.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/map.cpp.o: ../src/map.cpp
CMakeFiles/exe.dir/src/map.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exe.dir/src/map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/map.cpp.o -MF CMakeFiles/exe.dir/src/map.cpp.o.d -o CMakeFiles/exe.dir/src/map.cpp.o -c /home/void/Documents/CODES/TheProject/src/map.cpp

CMakeFiles/exe.dir/src/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/map.cpp > CMakeFiles/exe.dir/src/map.cpp.i

CMakeFiles/exe.dir/src/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/map.cpp -o CMakeFiles/exe.dir/src/map.cpp.s

CMakeFiles/exe.dir/src/wall.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/wall.cpp.o: ../src/wall.cpp
CMakeFiles/exe.dir/src/wall.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exe.dir/src/wall.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/wall.cpp.o -MF CMakeFiles/exe.dir/src/wall.cpp.o.d -o CMakeFiles/exe.dir/src/wall.cpp.o -c /home/void/Documents/CODES/TheProject/src/wall.cpp

CMakeFiles/exe.dir/src/wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/wall.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/wall.cpp > CMakeFiles/exe.dir/src/wall.cpp.i

CMakeFiles/exe.dir/src/wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/wall.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/wall.cpp -o CMakeFiles/exe.dir/src/wall.cpp.s

CMakeFiles/exe.dir/src/game.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/exe.dir/src/game.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exe.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/game.cpp.o -MF CMakeFiles/exe.dir/src/game.cpp.o.d -o CMakeFiles/exe.dir/src/game.cpp.o -c /home/void/Documents/CODES/TheProject/src/game.cpp

CMakeFiles/exe.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/game.cpp > CMakeFiles/exe.dir/src/game.cpp.i

CMakeFiles/exe.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/game.cpp -o CMakeFiles/exe.dir/src/game.cpp.s

CMakeFiles/exe.dir/src/pacman.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/pacman.cpp.o: ../src/pacman.cpp
CMakeFiles/exe.dir/src/pacman.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/exe.dir/src/pacman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/pacman.cpp.o -MF CMakeFiles/exe.dir/src/pacman.cpp.o.d -o CMakeFiles/exe.dir/src/pacman.cpp.o -c /home/void/Documents/CODES/TheProject/src/pacman.cpp

CMakeFiles/exe.dir/src/pacman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/pacman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/pacman.cpp > CMakeFiles/exe.dir/src/pacman.cpp.i

CMakeFiles/exe.dir/src/pacman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/pacman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/pacman.cpp -o CMakeFiles/exe.dir/src/pacman.cpp.s

CMakeFiles/exe.dir/src/ghost.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/ghost.cpp.o: ../src/ghost.cpp
CMakeFiles/exe.dir/src/ghost.cpp.o: CMakeFiles/exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/exe.dir/src/ghost.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exe.dir/src/ghost.cpp.o -MF CMakeFiles/exe.dir/src/ghost.cpp.o.d -o CMakeFiles/exe.dir/src/ghost.cpp.o -c /home/void/Documents/CODES/TheProject/src/ghost.cpp

CMakeFiles/exe.dir/src/ghost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/ghost.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/void/Documents/CODES/TheProject/src/ghost.cpp > CMakeFiles/exe.dir/src/ghost.cpp.i

CMakeFiles/exe.dir/src/ghost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/ghost.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/void/Documents/CODES/TheProject/src/ghost.cpp -o CMakeFiles/exe.dir/src/ghost.cpp.s

# Object files for target exe
exe_OBJECTS = \
"CMakeFiles/exe.dir/src/main.cpp.o" \
"CMakeFiles/exe.dir/src/tile.cpp.o" \
"CMakeFiles/exe.dir/src/map.cpp.o" \
"CMakeFiles/exe.dir/src/wall.cpp.o" \
"CMakeFiles/exe.dir/src/game.cpp.o" \
"CMakeFiles/exe.dir/src/pacman.cpp.o" \
"CMakeFiles/exe.dir/src/ghost.cpp.o"

# External object files for target exe
exe_EXTERNAL_OBJECTS =

exe: CMakeFiles/exe.dir/src/main.cpp.o
exe: CMakeFiles/exe.dir/src/tile.cpp.o
exe: CMakeFiles/exe.dir/src/map.cpp.o
exe: CMakeFiles/exe.dir/src/wall.cpp.o
exe: CMakeFiles/exe.dir/src/game.cpp.o
exe: CMakeFiles/exe.dir/src/pacman.cpp.o
exe: CMakeFiles/exe.dir/src/ghost.cpp.o
exe: CMakeFiles/exe.dir/build.make
exe: CMakeFiles/exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/void/Documents/CODES/TheProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exe.dir/build: exe
.PHONY : CMakeFiles/exe.dir/build

CMakeFiles/exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exe.dir/clean

CMakeFiles/exe.dir/depend:
	cd /home/void/Documents/CODES/TheProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/void/Documents/CODES/TheProject /home/void/Documents/CODES/TheProject /home/void/Documents/CODES/TheProject/build /home/void/Documents/CODES/TheProject/build /home/void/Documents/CODES/TheProject/build/CMakeFiles/exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exe.dir/depend

