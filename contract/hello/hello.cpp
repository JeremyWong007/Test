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