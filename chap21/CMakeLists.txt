add_executable(list2101 list2101.cpp)
target_compile_options(list2101 PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wno-unused-but-set-parameter>)
add_executable(list2102 list2102.cpp)

