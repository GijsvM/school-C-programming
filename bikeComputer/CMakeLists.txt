cmake_minimum_required(VERSION 3.0)
project(BikeComputer)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add source files
set(SOURCES
    main.c
    bike_math.c
    bike_measure.c
    bike_store.c
)

# Add header files
set(HEADERS
    bike_math.h
    bike_measure.h
    bike_store.h
)

# Create the executable
add_executable(bikeComputer ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(bikeComputer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add any necessary libraries
# target_link_libraries(bikeComputer <library_name>)

# Enable warnings
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(bikeComputer PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install target
install(TARGETS bikeComputer DESTINATION bin)