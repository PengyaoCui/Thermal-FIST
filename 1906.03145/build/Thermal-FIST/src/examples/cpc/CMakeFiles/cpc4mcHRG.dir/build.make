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
CMAKE_SOURCE_DIR = /home/cuipengyao/Thermal-FIST/1906.03145

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cuipengyao/Thermal-FIST/1906.03145/build

# Include any dependencies generated for this target.
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/depend.make

# Include the progress variables for this target.
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/progress.make

# Include the compile flags for this target's objects.
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/flags.make

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/flags.make
Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o: ../Thermal-FIST/src/examples/cpc/cpc4-mcHRG.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o -c /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc4-mcHRG.cpp

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.i"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc4-mcHRG.cpp > CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.i

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.s"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc4-mcHRG.cpp -o CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.s

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.requires:

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.requires

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.provides: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.requires
	$(MAKE) -f Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/build.make Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.provides.build
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.provides

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.provides.build: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o


# Object files for target cpc4mcHRG
cpc4mcHRG_OBJECTS = \
"CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o"

# External object files for target cpc4mcHRG
cpc4mcHRG_EXTERNAL_OBJECTS =

bin/examples/cpc4mcHRG: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o
bin/examples/cpc4mcHRG: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/build.make
bin/examples/cpc4mcHRG: lib/libThermalFIST.a
bin/examples/cpc4mcHRG: lib/libMinuit2.a
bin/examples/cpc4mcHRG: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/examples/cpc4mcHRG"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpc4mcHRG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/build: bin/examples/cpc4mcHRG

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/build

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/requires: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/cpc4-mcHRG.cpp.o.requires

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/requires

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/clean:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && $(CMAKE_COMMAND) -P CMakeFiles/cpc4mcHRG.dir/cmake_clean.cmake
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/clean

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/depend:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cuipengyao/Thermal-FIST/1906.03145 /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc /home/cuipengyao/Thermal-FIST/1906.03145/build /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc4mcHRG.dir/depend

