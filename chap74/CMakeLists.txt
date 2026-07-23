# GoogleTest ships as a source package on this system (/usr/src/googletest).
# Build it as part of this chapter so the test_mainN targets can link gtest.
if(NOT TARGET gtest)
  set(GOOGLETEST_SOURCE_DIR "/usr/src/googletest" CACHE PATH "GoogleTest source tree")
  if(EXISTS "${GOOGLETEST_SOURCE_DIR}/CMakeLists.txt")
    # Quiet gtest's own warnings; it must build with the project's C++ standard.
    add_subdirectory("${GOOGLETEST_SOURCE_DIR}"
                     "${CMAKE_BINARY_DIR}/_deps/googletest-build"
                     EXCLUDE_FROM_ALL)
  else()
    message(WARNING "GoogleTest source not found at ${GOOGLETEST_SOURCE_DIR}; "
                    "chap74 test targets will fail to link.")
  endif()
endif()

add_subdirectory(step1)
add_subdirectory(step2)
add_subdirectory(step3)
add_subdirectory(step4)
add_subdirectory(step5)
add_subdirectory(step6)
