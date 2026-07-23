add_executable(list3401 list3401.cpp list3401.hh)
add_executable(list3402 list3402.cpp list3402.hh)
add_executable(list3403 list3403.cpp)
add_executable(list3404 list3404.cpp list3404.hh)
add_executable(list3405 list3405.cpp list3405.hh)
add_executable(list3406 list3406.cpp)
target_compile_options(list3406 PRIVATE $<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-unused-variable>)

