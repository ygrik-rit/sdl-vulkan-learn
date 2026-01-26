if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    add_library(coverage SHARED)
else()
    add_executable(coverage)
endif()

target_sources(coverage PRIVATE coverage.cxx)

target_link_libraries(coverage PRIVATE svl::svl svl::base)
