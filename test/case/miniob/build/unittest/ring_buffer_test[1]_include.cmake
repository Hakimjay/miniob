if(EXISTS "/home/ajay/local/whu_ob/test/case/miniob/build/unittest/ring_buffer_test[1]_tests.cmake")
  include("/home/ajay/local/whu_ob/test/case/miniob/build/unittest/ring_buffer_test[1]_tests.cmake")
else()
  add_test(ring_buffer_test_NOT_BUILT ring_buffer_test_NOT_BUILT)
endif()
