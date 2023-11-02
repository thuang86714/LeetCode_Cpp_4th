#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> ans(2, -1);
        while(l <= r){
            int mid = (l + r)/2;
            if(target > nums[mid]){
                l = mid + 1;
            }else{
                if(nums[mid] == target){
                    ans[0] = mid;
                }
                r = mid - 1;
            }
        }
        
        l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(target < nums[mid]){
                r = mid - 1;
            }else{
                if(nums[mid] == target){
                    ans[1] = mid;
                }
                l = mid + 1;
            }
        }
        return ans;
    }
};