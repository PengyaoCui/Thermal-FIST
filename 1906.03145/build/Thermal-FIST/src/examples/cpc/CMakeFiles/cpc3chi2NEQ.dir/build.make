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
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/depend.make

# Include the progress variables for this target.
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/progress.make

# Include the compile flags for this target's objects.
include Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/flags.make

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/flags.make
Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o: ../Thermal-FIST/src/examples/cpc/cpc3-chi2NEQ.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o -c /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc3-chi2NEQ.cpp

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.i"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc3-chi2NEQ.cpp > CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.i

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.s"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc/cpc3-chi2NEQ.cpp -o CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.s

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.requires:

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.requires

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.provides: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.requires
	$(MAKE) -f Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/build.make Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.provides.build
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.provides

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.provides.build: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o


# Object files for target cpc3chi2NEQ
cpc3chi2NEQ_OBJECTS = \
"CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o"

# External object files for target cpc3chi2NEQ
cpc3chi2NEQ_EXTERNAL_OBJECTS =

bin/examples/cpc3chi2NEQ: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o
bin/examples/cpc3chi2NEQ: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/build.make
bin/examples/cpc3chi2NEQ: lib/libThermalFIST.a
bin/examples/cpc3chi2NEQ: lib/libMinuit2.a
bin/examples/cpc3chi2NEQ: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cuipengyao/Thermal-FIST/1906.03145/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/examples/cpc3chi2NEQ"
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpc3chi2NEQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/build: bin/examples/cpc3chi2NEQ

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/build

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/requires: Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/cpc3-chi2NEQ.cpp.o.requires

.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/requires

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/clean:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc && $(CMAKE_COMMAND) -P CMakeFiles/cpc3chi2NEQ.dir/cmake_clean.cmake
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/clean

Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/depend:
	cd /home/cuipengyao/Thermal-FIST/1906.03145/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cuipengyao/Thermal-FIST/1906.03145 /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/cpc /home/cuipengyao/Thermal-FIST/1906.03145/build /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc /home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Thermal-FIST/src/examples/cpc/CMakeFiles/cpc3chi2NEQ.dir/depend

