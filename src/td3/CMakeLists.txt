
set(APPS
    even_forward_iterator.cpp)

foreach (srcfile ${APPS})
    string (REPLACE ".cpp" "" app ${srcfile})
    add_executable(${app} ${srcfile})
endforeach()