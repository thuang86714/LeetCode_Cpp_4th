#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        findPermut(nums, 0);
        return res;
    }

private:
    void findPermut(vector<int> &nums, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            findPermut(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
};