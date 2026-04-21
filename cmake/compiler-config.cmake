function(svl_setup_global_compiler)
    add_link_options(-fuse-ld=mold)
    if (CMAKE_CXX_COMPILER MATCHES "clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        add_link_options(-lc++abi)
    elseif(CMAKE_CXX_COMPILER MATCHES "g++")

    else()
        message(FATAL_ERROR)
    endif()
endfunction()

function(svl_setup_target_compiler target)
    
endfunction()