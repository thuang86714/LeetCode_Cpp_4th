#include <vector>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        //credit to jacklee20499, TC O(n^2), SC O(n^2)
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return maxScore(0,nums.size()-1,nums, memo) >= 0;
    }
private:
    
    int maxScore(int begin, int end, vector<int>& nums,  vector<vector<int>> &memo) {
        if(memo[begin][end]!=-1)  return memo[begin][end];
        if(begin==end) return memo[begin][end] = nums[begin];
        return memo[begin][end] =  max(nums[begin] - maxScore(begin+1,end ,nums, memo), nums[end] - maxScore(begin,end-1,nums, memo));
    }
};

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n);

        for(int i=n-1; i>=0; i--){
            memo[i] = nums[i];
            for(int j=i+1; j<n; j++){
                memo[j] = max(nums[i] - memo[j], nums[j] - memo[j-1]);
            }
        }
        
        return memo[n-1]>=0;
    }
};