if(EXISTS "/home/ajay/local/whu_ob/test/case/miniob/build/unittest/persist_test[1]_tests.cmake")
  include("/home/ajay/local/whu_ob/test/case/miniob/build/unittest/persist_test[1]_tests.cmake")
else()
  add_test(persist_test_NOT_BUILT persist_test_NOT_BUILT)
endif()
