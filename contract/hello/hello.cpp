#include <eosio/eosio.hpp>

//using namespace eosio;

class [[eosio::contract]] hello : public eosio::contract {
  public:
      using eosio::contract::contract;

      [[eosio::action]]
      void hi( eosio::name user ) {
         eosio::print( "Hello5, ", user);
      }
};