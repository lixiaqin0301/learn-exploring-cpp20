add_executable(list1201 list1201.cpp)
add_executable(list1202 list1202.cpp)
target_compile_options(list1202 PRIVATE $<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-literal-conversion>)
add_executable(list1204 list1204.cpp)
add_executable(list1205 list1205.cpp)
add_executable(list1206 list1206.cpp)

