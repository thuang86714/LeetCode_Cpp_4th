#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0;
        for(int i = 0; i < 31; i++){
            sum = n%2 + sum<<1;
            n>>=1;
        }
        sum += n%2;
        return sum;
    }
};