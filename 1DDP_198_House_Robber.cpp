#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 3){
            return *max_element(nums.begin(), nums.end());
        }
        int n = nums.size();
        vector<int> memo(n);
        for(int i = 0; i< n; i++){
            if(i == 0){
                memo[i] = nums[i];
                continue;
            }
            if(i == 1){
                memo[i] = max(nums[i], nums[i - 1]);
                continue;
            }
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }

        return memo.back();
    }
};