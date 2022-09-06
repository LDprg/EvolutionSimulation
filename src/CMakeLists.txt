file(GLOB SRC "*.c" "*.cpp" "*.cc" "*.h" "*.hpp")

add_executable(${PROJECT_NAME} ${SRC})

# link
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

# Copy SFML Dlls
if (SHARED_LIB)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-audio> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-network> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-system> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-window> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )
endif ()