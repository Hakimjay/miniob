if(EXISTS "/home/ajay/local/whu_ob/test/case/miniob/build/unitest/rc_test[1]_tests.cmake")
  include("/home/ajay/local/whu_ob/test/case/miniob/build/unitest/rc_test[1]_tests.cmake")
else()
  add_test(rc_test_NOT_BUILT rc_test_NOT_BUILT)
endif()