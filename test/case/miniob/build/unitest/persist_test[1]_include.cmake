if(EXISTS "/home/ajay/local/miniob/test/case/miniob/build/unitest/persist_test[1]_tests.cmake")
  include("/home/ajay/local/miniob/test/case/miniob/build/unitest/persist_test[1]_tests.cmake")
else()
  add_test(persist_test_NOT_BUILT persist_test_NOT_BUILT)
endif()
