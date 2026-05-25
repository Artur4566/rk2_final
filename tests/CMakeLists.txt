include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_adapter test_adapter.cpp)
target_link_libraries(test_adapter PRIVATE adapter_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(test_adapter)
