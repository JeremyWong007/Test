# CMake generated Testfile for 
# Source directory: /home/yanfa-1/info/git/test/linux_project/normal
# Build directory: /home/yanfa-1/info/git/test/linux_project/normal/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "test1" "5" "2")
add_test(test_usage "test1" "3" "2")
subdirs("boost_test")
subdirs("stl_test")
subdirs("sundries")
