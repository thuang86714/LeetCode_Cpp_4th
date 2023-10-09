#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_mini = 30001, cur_maxi = -30001, maxi = INT_MIN, mini = INT_MAX, total = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_maxi = max(cur_maxi + nums[i], nums[i]);
            maxi = max(cur_maxi, maxi);

            cur_mini = min(cur_mini + nums[i], nums[i]);
            mini = min(cur_mini, mini);

            total += nums[i];
        }

        if(maxi < 0){
            return maxi;
        }else{
            return max(maxi, total - mini);
        }
    }
};