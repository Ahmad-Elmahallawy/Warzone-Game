# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\oimbs\CLionProjects\COMP345-Warzone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_1.dir/flags.make

CMakeFiles/Project_1.dir/Map/Map.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Map/Map.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Map/Map.cpp
CMakeFiles/Project_1.dir/Map/Map.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_1.dir/Map/Map.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Map/Map.cpp.obj -MF CMakeFiles\Project_1.dir\Map\Map.cpp.obj.d -o CMakeFiles\Project_1.dir\Map\Map.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\Map.cpp

CMakeFiles/Project_1.dir/Map/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Map/Map.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\Map.cpp > CMakeFiles\Project_1.dir\Map\Map.cpp.i

CMakeFiles/Project_1.dir/Map/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Map/Map.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\Map.cpp -o CMakeFiles\Project_1.dir\Map\Map.cpp.s

CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Map/MapDriver.cpp
CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj -MF CMakeFiles\Project_1.dir\Map\MapDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\Map\MapDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\MapDriver.cpp

CMakeFiles/Project_1.dir/Map/MapDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Map/MapDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\MapDriver.cpp > CMakeFiles\Project_1.dir\Map\MapDriver.cpp.i

CMakeFiles/Project_1.dir/Map/MapDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Map/MapDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Map\MapDriver.cpp -o CMakeFiles\Project_1.dir\Map\MapDriver.cpp.s

CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Cards/Cards.cpp
CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj -MF CMakeFiles\Project_1.dir\Cards\Cards.cpp.obj.d -o CMakeFiles\Project_1.dir\Cards\Cards.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\Cards.cpp

CMakeFiles/Project_1.dir/Cards/Cards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Cards/Cards.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\Cards.cpp > CMakeFiles\Project_1.dir\Cards\Cards.cpp.i

CMakeFiles/Project_1.dir/Cards/Cards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Cards/Cards.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\Cards.cpp -o CMakeFiles\Project_1.dir\Cards\Cards.cpp.s

CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Cards/CardsDriver.cpp
CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj -MF CMakeFiles\Project_1.dir\Cards\CardsDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\Cards\CardsDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\CardsDriver.cpp

CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\CardsDriver.cpp > CMakeFiles\Project_1.dir\Cards\CardsDriver.cpp.i

CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Cards\CardsDriver.cpp -o CMakeFiles\Project_1.dir\Cards\CardsDriver.cpp.s

CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Orders/Orders.cpp
CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj -MF CMakeFiles\Project_1.dir\Orders\Orders.cpp.obj.d -o CMakeFiles\Project_1.dir\Orders\Orders.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\Orders.cpp

CMakeFiles/Project_1.dir/Orders/Orders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Orders/Orders.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\Orders.cpp > CMakeFiles\Project_1.dir\Orders\Orders.cpp.i

CMakeFiles/Project_1.dir/Orders/Orders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Orders/Orders.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\Orders.cpp -o CMakeFiles\Project_1.dir\Orders\Orders.cpp.s

CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Orders/OrdersDriver.cpp
CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj -MF CMakeFiles\Project_1.dir\Orders\OrdersDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\Orders\OrdersDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\OrdersDriver.cpp

CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\OrdersDriver.cpp > CMakeFiles\Project_1.dir\Orders\OrdersDriver.cpp.i

CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Orders\OrdersDriver.cpp -o CMakeFiles\Project_1.dir\Orders\OrdersDriver.cpp.s

CMakeFiles/Project_1.dir/Players/Player.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Players/Player.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Players/Player.cpp
CMakeFiles/Project_1.dir/Players/Player.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project_1.dir/Players/Player.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Players/Player.cpp.obj -MF CMakeFiles\Project_1.dir\Players\Player.cpp.obj.d -o CMakeFiles\Project_1.dir\Players\Player.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\Player.cpp

CMakeFiles/Project_1.dir/Players/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Players/Player.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\Player.cpp > CMakeFiles\Project_1.dir\Players\Player.cpp.i

CMakeFiles/Project_1.dir/Players/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Players/Player.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\Player.cpp -o CMakeFiles\Project_1.dir\Players\Player.cpp.s

CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Players/PlayerDriver.cpp
CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj -MF CMakeFiles\Project_1.dir\Players\PlayerDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\Players\PlayerDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\PlayerDriver.cpp

CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\PlayerDriver.cpp > CMakeFiles\Project_1.dir\Players\PlayerDriver.cpp.i

CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Players\PlayerDriver.cpp -o CMakeFiles\Project_1.dir\Players\PlayerDriver.cpp.s

CMakeFiles/Project_1.dir/MainDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/MainDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/MainDriver.cpp
CMakeFiles/Project_1.dir/MainDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Project_1.dir/MainDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/MainDriver.cpp.obj -MF CMakeFiles\Project_1.dir\MainDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\MainDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\MainDriver.cpp

CMakeFiles/Project_1.dir/MainDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/MainDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\MainDriver.cpp > CMakeFiles\Project_1.dir\MainDriver.cpp.i

CMakeFiles/Project_1.dir/MainDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/MainDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\MainDriver.cpp -o CMakeFiles\Project_1.dir\MainDriver.cpp.s

CMakeFiles/Project_1.dir/GameEngine.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/GameEngine.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/GameEngine.cpp
CMakeFiles/Project_1.dir/GameEngine.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Project_1.dir/GameEngine.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/GameEngine.cpp.obj -MF CMakeFiles\Project_1.dir\GameEngine.cpp.obj.d -o CMakeFiles\Project_1.dir\GameEngine.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngine.cpp

CMakeFiles/Project_1.dir/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/GameEngine.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngine.cpp > CMakeFiles\Project_1.dir\GameEngine.cpp.i

CMakeFiles/Project_1.dir/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/GameEngine.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngine.cpp -o CMakeFiles\Project_1.dir\GameEngine.cpp.s

CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/GameEngineDriver.cpp
CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj -MF CMakeFiles\Project_1.dir\GameEngineDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\GameEngineDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngineDriver.cpp

CMakeFiles/Project_1.dir/GameEngineDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/GameEngineDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngineDriver.cpp > CMakeFiles\Project_1.dir\GameEngineDriver.cpp.i

CMakeFiles/Project_1.dir/GameEngineDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/GameEngineDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\GameEngineDriver.cpp -o CMakeFiles\Project_1.dir\GameEngineDriver.cpp.s

CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Command/CommandProcessing.cpp
CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj -MF CMakeFiles\Project_1.dir\Command\CommandProcessing.cpp.obj.d -o CMakeFiles\Project_1.dir\Command\CommandProcessing.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\CommandProcessing.cpp

CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\CommandProcessing.cpp > CMakeFiles\Project_1.dir\Command\CommandProcessing.cpp.i

CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\CommandProcessing.cpp -o CMakeFiles\Project_1.dir\Command\CommandProcessing.cpp.s

CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj: C:/Users/oimbs/CLionProjects/COMP345-Warzone/Command/commandProcessingDriver.cpp
CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj -MF CMakeFiles\Project_1.dir\Command\commandProcessingDriver.cpp.obj.d -o CMakeFiles\Project_1.dir\Command\commandProcessingDriver.cpp.obj -c C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\commandProcessingDriver.cpp

CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\commandProcessingDriver.cpp > CMakeFiles\Project_1.dir\Command\commandProcessingDriver.cpp.i

CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oimbs\CLionProjects\COMP345-Warzone\Command\commandProcessingDriver.cpp -o CMakeFiles\Project_1.dir\Command\commandProcessingDriver.cpp.s

# Object files for target Project_1
Project_1_OBJECTS = \
"CMakeFiles/Project_1.dir/Map/Map.cpp.obj" \
"CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj" \
"CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj" \
"CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/Players/Player.cpp.obj" \
"CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/MainDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/GameEngine.cpp.obj" \
"CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj" \
"CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj" \
"CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj"

# External object files for target Project_1
Project_1_EXTERNAL_OBJECTS =

Project_1.exe: CMakeFiles/Project_1.dir/Map/Map.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Map/MapDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Cards/Cards.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Cards/CardsDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Orders/Orders.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Orders/OrdersDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Players/Player.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Players/PlayerDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/MainDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/GameEngine.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/GameEngineDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Command/CommandProcessing.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/Command/commandProcessingDriver.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/build.make
Project_1.exe: CMakeFiles/Project_1.dir/linkLibs.rsp
Project_1.exe: CMakeFiles/Project_1.dir/objects1.rsp
Project_1.exe: CMakeFiles/Project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable Project_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_1.dir/build: Project_1.exe
.PHONY : CMakeFiles/Project_1.dir/build

CMakeFiles/Project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project_1.dir/clean

CMakeFiles/Project_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\oimbs\CLionProjects\COMP345-Warzone C:\Users\oimbs\CLionProjects\COMP345-Warzone C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug C:\Users\oimbs\CLionProjects\COMP345-Warzone\cmake-build-debug\CMakeFiles\Project_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_1.dir/depend

