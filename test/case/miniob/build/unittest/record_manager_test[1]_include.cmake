if(EXISTS "/home/ajay/local/whu_ob/test/case/miniob/build/unittest/record_manager_test[1]_tests.cmake")
  include("/home/ajay/local/whu_ob/test/case/miniob/build/unittest/record_manager_test[1]_tests.cmake")
else()
  add_test(record_manager_test_NOT_BUILT record_manager_test_NOT_BUILT)
endif()
