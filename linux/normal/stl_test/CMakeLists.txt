#所有的路径变量都不允许重名
AUX_SOURCE_DIRECTORY(. STLTEST_SRC_LIST)
#设置成静态库
ADD_LIBRARY(stl_test ${STLTEST_SRC_LIST})

INCLUDE_DIRECTORIES(/home/yanfa-1/eosio/2.0/src/boost_1_71_0/include/)
INCLUDE_DIRECTORIES(/usr/local/include/orocos)