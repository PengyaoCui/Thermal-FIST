# Install script for directory: /home/cuipengyao/Thermal-FIST/1906.03145/Thermal-FIST/src/examples/CalculationTmu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples" TYPE EXECUTABLE FILES "/home/cuipengyao/Thermal-FIST/1906.03145/build/bin/examples/CalculationTmu")
  if(EXISTS "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu"
         OLD_RPATH "/home/cuipengyao/alice/sw/ubuntu1804_x86-64/ROOT/v6-16-00-1/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/cuipengyao/Thermal-FIST/1906.03145/build/Thermal-FIST/bin/examples/CalculationTmu")
    endif()
  endif()
endif()

