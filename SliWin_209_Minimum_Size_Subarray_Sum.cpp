#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, r = 0, l = 0, n = nums.size(), len = 10e6;
        for(; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                len = min(len, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if(len == 10e6){
            return 0;
        }else{
            return len;
        }
    }
};