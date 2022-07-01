project(test_vector)

add_executable(${PROJECT_NAME} main.cpp tests.cpp)

target_link_libraries(${PROJECT_NAME} vector)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
