#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        findSubset(nums, cur, 0);
        return res;
    }
private:
    void findSubset(vector<int> &nums, vector<int> &cur, int idx){
        res.push_back(cur);

        if(idx == nums.size()){
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            findSubset(nums, cur, i + 1);
            cur.pop_back();
        }
    }
};
