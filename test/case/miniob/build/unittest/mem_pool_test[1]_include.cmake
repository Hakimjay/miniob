if(EXISTS "/home/ajay/local/whu_ob/test/case/miniob/build/unittest/mem_pool_test[1]_tests.cmake")
  include("/home/ajay/local/whu_ob/test/case/miniob/build/unittest/mem_pool_test[1]_tests.cmake")
else()
  add_test(mem_pool_test_NOT_BUILT mem_pool_test_NOT_BUILT)
endif()