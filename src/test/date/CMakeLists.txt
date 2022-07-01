project(test_date)

add_executable(${PROJECT_NAME} main.cpp tests.cpp)

target_link_libraries(${PROJECT_NAME} date)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
