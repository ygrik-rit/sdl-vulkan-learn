add_subdirectory(device)
add_subdirectory(window)
add_subdirectory(render)

add_library(svl OBJECT)
target_sources(svl PUBLIC FILE_SET svl_module TYPE CXX_MODULES FILES svl.cxxm)
target_link_libraries(svl PRIVATE svl::base svl::window svl::render)

add_library(svl::svl ALIAS svl)
