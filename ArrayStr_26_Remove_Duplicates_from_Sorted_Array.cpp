#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1 - count]){
                count++;
            }else{
                nums[i - count] = nums[i];
            }
        }
        return nums.size() - count;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, val = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != val){
                nums[idx] = nums[i];
                idx++;
                val = nums[i];
            }
        }
        return idx;
    }
};