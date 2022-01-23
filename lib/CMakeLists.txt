add_library(container STATIC src/container.cpp src/operation.cpp)
target_include_directories(container PUBLIC include)
target_link_libraries(container pthread)
