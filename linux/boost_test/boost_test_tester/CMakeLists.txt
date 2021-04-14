CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )

PROJECT(TEST)

#自己定制
SET(MY_TARGET utf_test)
#SET(MY_LINK boost_test stl_test sundries_test)

#设置编译器
SET(CMAKE_CXX_COMPILER "g++")

MESSAGE(STATUS "This is BINARY dir " ${TEST_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${TEST_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#设置构建类型，及相应的编译选项
SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -DNDEBUG")

#设置执行文件输出目录
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设置库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

MESSAGE("++++++++++++++Start Build+++++++++++++++++")

#当前目录的文件
AUX_SOURCE_DIRECTORY(. SRC_LIST)
#添加子目录

set(Boost_INCLUDE_DIR /usr/local/include)
set(Boost_LIBRARY_DIR /usr/local/lib)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#头文件搜索目录
include_directories(${Boost_INCLUDE_DIR})

#链接库搜索路径
#LINK_DIRECTORIES(lib /home/yanfa-1/eosio/2.0/src/boost_1_71_0/lib)
link_directories(lib ${Boost_LIBRARY_DIR})
#设置链接库
SET(EXTRA_LIBS ${EXTRA_LIBS} ${MY_LINK})

#生成可执行文件
ADD_EXECUTABLE(${MY_TARGET} ${SRC_LIST})
#执行文件链接属性
TARGET_LINK_LIBRARIES(${MY_TARGET} ${EXTRA_LIBS} ${Boost_LIBRARIES})

install (TARGETS ${MY_TARGET} DESTINATION bin)
#install (FILES "boost_test/boost_test.h" DESTINATION include)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run ${MY_TARGET} 5 2)
add_test (test_usage  ${MY_TARGET} 3 2)


add_definitions(-DTEST_IN_LINUX)
set(SAYHELLO "sdf")
add_definitions(-DSHOWSTR="${SAYHELLO}")

set(TEST_ON 1)
set(TEST_OF 0)
set(VAR "010")