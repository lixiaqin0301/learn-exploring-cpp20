add_executable(list0401 list0401.cpp)
add_executable(list0402 list0402.cpp)
add_executable(list0403 list0403.cpp)
add_executable(list0404 list0404.cpp)
add_executable(list0405 list0405.cpp)

add_executable(list0406 list0406.cpp)
target_compile_options(list0406 PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wno-maybe-uninitialized> $<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-uninitialized> $<$<CXX_COMPILER_ID:MSVC>:/w44700>)
