# cmake -P tests/res/textures/convert.cmake

# TODO: Rewrite it with C++ api for working with this textures in editor
find_program(ktx NAMES ktx DOC "System tool for create/work with KTX textures")

file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.png")

foreach(source ${sources})
    get_filename_component(output ${source} NAME_WLE)
    get_filename_component(dir ${source} DIRECTORY)
    set(output ${dir}/${output}.ktx)
    execute_process(
        COMMAND ${ktx} create --format=R8G8B8_SRGB ${source} ${output}
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
endforeach()
