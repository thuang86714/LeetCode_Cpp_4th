#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefix = 1;
        vector<int> res(n, 1);
        for(int i = 1; i < nums.size(); i++){
            prefix *= nums[i - 1];
            res[i] = prefix;
        }
        int postfix = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            postfix *= nums[i + 1];
            res[i] *= postfix;
        }
        return res;
    }
};