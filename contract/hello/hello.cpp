#include <tafio/tafio.hpp>

//using namespace tafio;

class [[tafio::contract]] hello : public tafio::contract {
  public:
      using tafio::contract::contract;

      [[tafio::action]]
      void hi( tafio::name user ) {
         tafio::print( "Hello7, ", user);
      }
};