#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r= nums.size() -1;
        while(l < r){
            int mid = (l + r)/2;
            if(nums[l] < nums[r]){
                return nums[l];
            }
            if(nums[l] <= nums[mid]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return nums[l];
    }
};