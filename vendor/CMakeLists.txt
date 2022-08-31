# SFML
set(BUILD_SHARED_LIBS SHARED_LIB)

add_subdirectory(sfml)

target_include_directories(${PROJECT_NAME} PUBLIC sfml/include)
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

#entt
add_subdirectory(entt)

target_include_directories(${PROJECT_NAME} PUBLIC entt/src)