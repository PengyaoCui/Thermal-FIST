set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}/include")
add_executable (1906.03145.1 1906.03145.1.cpp)
target_link_libraries (1906.03145.1 ThermalFIST)
set_property(TARGET 1906.03145.1 PROPERTY FOLDER "1906.03145")
install (TARGETS 1906.03145.1 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

add_executable (1906.03145.2 1906.03145.2.cpp)
target_link_libraries (1906.03145.2 ThermalFIST)
set_property(TARGET 1906.03145.2 PROPERTY FOLDER "1906.03145")
install (TARGETS 1906.03145.2 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

add_executable (1906.03145.3 1906.03145.3.cpp)
target_link_libraries (1906.03145.3 ThermalFIST)
set_property(TARGET 1906.03145.3 PROPERTY FOLDER "1906.03145")
install (TARGETS 1906.03145.3 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
		 
add_executable (1906.03145.4 1906.03145.4.cpp)
target_link_libraries (1906.03145.4 ThermalFIST)
set_property(TARGET 1906.03145.4 PROPERTY FOLDER "1906.03145")
install (TARGETS 1906.03145.4 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
