#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, n = nums.size(), lastPos = 0, maxReachable = 0, jump = 0;
        while(lastPos < n - 1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(i ==lastPos){
                lastPos = maxReachable;
                jump++;
            }
            i++;
        }
        return jump;
    }
};