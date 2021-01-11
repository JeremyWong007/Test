cmake_minimum_required( VERSION 3.8 )

PROJECT(TEST)
SET(SRC_LIST main.cpp)
MESSAGE(STATUS "This is BINARY dir " ${TEST_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${TEST_SOURCE_DIR})

INCLUDE_DIRECTORIES(/home/yanfa-1/eosio/2.0/src/boost_1_71_0/include/)

ADD_EXECUTABLE(test ${SRC_LIST})