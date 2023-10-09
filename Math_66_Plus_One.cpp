#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() != 9){
            digits.back()++;
            return digits;
        }

        for(int i = digits.size() -1; i >= 0; i--){
            if(i == digits.size() - 1)digits[i]++;

            if(digits[i] == 10){
                if(i == 0){
                    digits[i] = 1;
                    digits.push_back(0);
                }else{
                    digits[i] = 0;
                    digits[i - 1]++;
                }
            }
        }

        return digits;
    }
};