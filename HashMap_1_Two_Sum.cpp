#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //<num, pos>
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            if(dict.find(target - nums[i]) != dict.end()){
                return {dict[target - nums[i]], i};
            }
            dict[nums[i]] = i;
        }
        return {};
    }
};