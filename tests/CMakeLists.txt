cmake_minimum_required(VERSION 3.28)
project(algorithm_tests)

include(GoogleTest)

file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS "*.cpp")

foreach(TEST_FILE ${TEST_FILES})
  cmake_path(GET TEST_FILE STEM TEST_NAME)
  
  add_executable(${TEST_NAME} ${TEST_FILE})
  target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest GTest::gtest_main pthread)

  gtest_discover_tests(${TEST_NAME})
endforeach()
