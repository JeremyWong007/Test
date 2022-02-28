/*
使用说明：
1 编译
tafsys-cpp -o hello.wasm hello.cpp

2 部署
tafclient update contract T17VzCrQddyUgzWhEk9AKykPhPZrEDW4ktV ./

3 调用action
tafclient send action T17VzCrQddyUgzWhEk9AKykPhPZrEDW4ktV hi '["user1"]' -p T17VzCrQddyUgzWhEk9AKykPhPZrEDW4ktV
*/

#include <tafsys/tafsys.hpp>

//using namespace tafsys;

class [[tafsys::contract]] hello : public tafsys::contract {
  public:
      using tafsys::contract::contract;

      [[tafsys::action]]
      void hi( tafsys::name user ) {
         tafsys::print( "Hello7, ", user);
      }
};