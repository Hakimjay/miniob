add_test( test_record_page_handler.test_record_page_handler /home/ajay/local/miniob/test/case/miniob/build/bin/record_manager_test [==[--gtest_filter=test_record_page_handler.test_record_page_handler]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_record_page_handler.test_record_page_handler PROPERTIES WORKING_DIRECTORY /home/ajay/local/miniob/test/case/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( test_record_page_handler.test_record_file_iterator /home/ajay/local/miniob/test/case/miniob/build/bin/record_manager_test [==[--gtest_filter=test_record_page_handler.test_record_file_iterator]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_record_page_handler.test_record_file_iterator PROPERTIES WORKING_DIRECTORY /home/ajay/local/miniob/test/case/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( record_manager_test_TESTS test_record_page_handler.test_record_page_handler test_record_page_handler.test_record_file_iterator)
