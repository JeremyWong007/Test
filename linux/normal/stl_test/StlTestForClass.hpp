#include <iostream>

using namespace std;

struct signed_transaction
{

};

class packed_transaction
{
    public:
    packed_transaction(signed_transaction st){

    };
};
class stlTestForClass
{
    public:
    stlTestForClass(){
        std::shared_ptr<std::vector<signed_transaction>> trxs;
        signed_transaction st;
        trxs->emplace_back(st);
        //test_lamda([=](){n+=5;cout<<"n is "<<n<<endl;});
        accept_transaction( std::make_shared<packed_transaction>(trxs->at(0)));
    };
    void test_lamda(std::function<void()> f){f();};

    using packed_transaction_ptr = std::shared_ptr<packed_transaction>;
    void accept_transaction(const packed_transaction_ptr& trx) {
        //my->incoming_transaction_async_method(trx, false, std::move(next));
    }

    private:
    int n=0;
    int j=0;
    std::shared_ptr<std::vector<signed_transaction>> trxs;
};