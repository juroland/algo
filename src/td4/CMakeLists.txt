
set(APPS
    map_perf.cpp
    reverse_telephone_dictionary.cpp)

foreach (srcfile ${APPS})
    string (REPLACE ".cpp" "" app ${srcfile})
    add_executable(${app} ${srcfile})
endforeach()