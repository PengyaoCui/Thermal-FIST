# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/cuipengyao/Thermal-FIST/1906.03145

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cuipengyao/Thermal-FIST/1906.03145/build

# Include any dependencies generated for this target.
include Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/depend.make

# Include the progress variables for this target.
include Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/progress.make

# Include the compile flags for this target's objects.
include Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/flags.make

Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o: Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/flags.make
Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o: ../Thermal-FIST/src/examples/PCE/PCE-Saha-LHC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o -c /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/PCE/PCE-Saha-LHC.cpp

Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.i"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/PCE/PCE-Saha-LHC.cpp > CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.i

Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.s"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/PCE/PCE-Saha-LHC.cpp -o CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.s

# Object files for target PCE-Saha-LHC
PCE__Saha__LHC_OBJECTS = \
"CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o"

# External object files for target PCE-Saha-LHC
PCE__Saha__LHC_EXTERNAL_OBJECTS =

bin/examples/PCE-Saha-LHC: Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/PCE-Saha-LHC.cpp.o
bin/examples/PCE-Saha-LHC: Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/build.make
bin/examples/PCE-Saha-LHC: lib/libThermalFIST.a
bin/examples/PCE-Saha-LHC: lib/libMinuit2.a
bin/examples/PCE-Saha-LHC: Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/examples/PCE-Saha-LHC"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PCE-Saha-LHC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/build: bin/examples/PCE-Saha-LHC

.PHONY : Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/build

Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/clean:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE && $(CMAKE_COMMAND) -P CMakeFiles/PCE-Saha-LHC.dir/cmake_clean.cmake
.PHONY : Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/clean

Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/depend:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cuipengyao/Thermal-FIST/1906.03145 /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/PCE /home/cuipengyao/Thermal-FIST/1906.03145/build /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Thermal-FIST/src/examples/PCE/CMakeFiles/PCE-Saha-LHC.dir/depend

