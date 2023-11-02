#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            step++;
            if(nums[i] >= step){
                step = 0;
            }
        }

        return step == 0;
    }
};