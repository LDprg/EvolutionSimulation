# SFML
set(BUILD_SHARED_LIBS ${SHARED_LIB})

add_subdirectory(sfml)

target_include_directories(${PROJECT_NAME} PUBLIC sfml/include)

# entt
add_subdirectory(entt)

target_include_directories(${PROJECT_NAME} PUBLIC entt/src)

# eigen
add_subdirectory(eigen)

target_include_directories(${PROJECT_NAME} PUBLIC eigen)
