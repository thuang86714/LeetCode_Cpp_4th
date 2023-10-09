#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort to make duplicate adjacent
        //TC O(nlogn), SC O(1)
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            int l = i+1, r = nums.size() - 1, target = -1*nums[i];
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < target){
                    l++;
                }else if(sum > target){
                    r--;
                }else{
                    vector<int> temp {nums[i], nums[l], nums[r]};
                    res.push_back(temp);
                    while(l < r && nums[l] == temp[1])l++;
                    while(l < r && nums[r] == temp[2])r--;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])i++;

        }
        return res;
    }
};