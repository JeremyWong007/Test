/*
log4cpp使用说明：
1 log4cpp.properties为配置文件，在其中配置日志优先级、文件大小、输出格式等详细信息
2 在需要使用的日志文件中包含头文件，并获取引用，例：log4cpp::Category& boostCategory = root.getInstance("boost");
3 通过“mainCategory.debug/info/warn/error/fatal”输出日志
安装说明：
1 git clone https://github.com/orocos-toolchain/log4cpp.git
2 mkdir build; cd build/; cmake ..; make -j8; sudo make install
*/
#pragma once
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/PropertyConfigurator.hh>

extern log4cpp::Category& root;
extern log4cpp::Category& mainCategory;
#define __format(__fmt__)  "%s:%d]: " __fmt__ 
#define dlog(__fmt__, ...)   mainCategory.debug(__format(__fmt__),__FILE__, __LINE__,##__VA_ARGS__)
#define ilog(__fmt__, ...)   mainCategory.info(__format(__fmt__),__FILE__, __LINE__,##__VA_ARGS__)
#define elog(__fmt__, ...)   mainCategory.error(__format(__fmt__),__FILE__, __LINE__,##__VA_ARGS__)

