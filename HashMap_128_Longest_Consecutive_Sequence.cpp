#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = true;
        }

        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i] - 1) > 0)map[nums[i]] = false;
        }
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]]){
                int j = 0, count = 0;
                while(map.count(nums[i] + j) > 0){
                    j++;
                    count++;
                }
                maxlen = max(count, maxlen);
            }
        }
        return maxlen;
    }
};