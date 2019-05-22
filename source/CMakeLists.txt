# Build example
add_executable(example example.cpp)

# Build gui
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_executable(gui gui.cpp)
target_link_libraries(gui ${GTKMM_LIBRARIES})

# Build tests
add_executable(tests tests.cpp)