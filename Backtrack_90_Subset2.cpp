#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        findSubset(nums, temp, 0);
        return res;
    }
private:
    void findSubset(vector<int> &nums, vector<int> &cur, int idx){
        res.push_back(cur);

        if(idx == nums.size()){
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i - 1]){
                continue;
            }
            cur.push_back(nums[i]);
            findSubset(nums, cur, i + 1);
            cur.pop_back();
        }
    }
};