function(svl_add_resources)
    # gersemi: hints { TARGET: pairs, DESTINATION: pairs, FOLDERS: sort+unique, FILES: sort+unique }
    cmake_parse_arguments(
        PARSE_ARGV
        0
        "ARG"
        "USE_SYMLINKS"
        "TARGET;DESTINATION"
        "FOLDERS;FILES"
    )
    if(${ARG_USE_SYMLINKS})
        set(folder_add_command create_symlink)
        set(file_add_command create_symlink)
    else()
        set(folder_add_command copy_directory_if_different)
        set(file_add_command copy_if_different)
    endif()
    foreach(folder ${ARG_FOLDERS})
        get_filename_component(base_name ${folder} NAME)
        add_custom_command(
            TARGET ${ARG_TARGET}
            POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} -E make_directory
                $<TARGET_FILE_DIR:${ARG_TARGET}>/${ARG_DESTINATION}/
            COMMAND
                ${CMAKE_COMMAND} -E ${folder_add_command} ${folder}
                $<TARGET_FILE_DIR:${ARG_TARGET}>/${ARG_DESTINATION}/${base_name}
        )
        install(
            DIRECTORY ${folder}
            # TODO: use share folder for resources in unix structure
            DESTINATION bin/${ARG_DESTINATION}
        )
    endforeach()
    foreach(file ${ARG_FILES})
        add_custom_command(
            TARGET ${ARG_TARGET}
            POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} -E ${file_add_command} ${file}
                $<TARGET_FILE_DIR:${ARG_TARGET}>/${ARG_DESTINATION}/
        )
    endforeach()
    install(
        FILES ${ARG_FILES}
        DESTINATION $<TARGET_FILE_DIR:${ARG_TARGET}>/${ARG_DESTINATION}
    )
endfunction()
