#所有的路径变量都不允许重名
AUX_SOURCE_DIRECTORY(. SUNDRIES_SRC_LIST)
#设置成静态库
#ADD_LIBRARY(sundries_test ${SUNDRIES_SRC_LIST})
INCLUDE_DIRECTORIES(/usr/local/include/orocos)
