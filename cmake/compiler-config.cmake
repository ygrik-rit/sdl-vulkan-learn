function(svl_setup_global_compiler)
    add_link_options(-fuse-ld=mold)
    if(CMAKE_CXX_COMPILER MATCHES "clang\\+\\+")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        add_link_options(-lc++abi)
    elseif(CMAKE_CXX_COMPILER MATCHES "g\\+\\+")

    else()
        message(FATAL_ERROR "Unknown compiler: '${CMAKE_CXX_COMPILER}'")
    endif()
endfunction()

function(svl_setup_target_compiler target)
    target_compile_options(
        ${target}
        INTERFACE
            -Werror
            -Wpedantic
            -Wall
            $<$<CXX_COMPILER_ID:Clang>:
            -Wno-c2y-extensions
            $<$<BOOL:${SVL_COVERAGE}>:
            -fprofile-instr-generate
            -fcoverage-mapping
            >
            >
            $<$<CXX_COMPILER_ID:GNU>:
            -Wextra
            $<$<BOOL:${SVL_COVERAGE}>:
            --coverage
            >
            >
    )
    target_link_options(
        ${target}
        INTERFACE
            $<$<CXX_COMPILER_ID:Clang>:
            $<$<BOOL:${SVL_COVERAGE}>:
            -fprofile-instr-generate
            -fcoverage-mapping
            >
            >
            $<$<CXX_COMPILER_ID:GNU>:
            $<$<BOOL:${SVL_COVERAGE}>:
            --coverage
            >
            >
    )
endfunction()
