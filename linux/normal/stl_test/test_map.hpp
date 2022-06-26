#include <map>
#include <vector>

using namespace std;

class test_map
{
private:
    /* data */
public:
    test_map(/* args */);
    ~test_map();
    std::map<int, std::vector<uint8_t>> vrf_proofs;
};

test_map::test_map(/* args */)
{
    if(vrf_proofs.count(10) == 0){
        vrf_proofs[10] = std::vector<uint8_t>();
    }
}

test_map::~test_map()
{
}
