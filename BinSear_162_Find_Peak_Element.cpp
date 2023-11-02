#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid1 = (l + r)/2;
            int mid2 = mid1 + 1;
            if(nums[mid1] > nums[mid2]){
                r = mid1;
            }else{
                l = mid2;
            }
        }

        return l;
    }
};