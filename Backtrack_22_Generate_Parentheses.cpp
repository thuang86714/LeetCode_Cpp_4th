#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;
    vector<int> cur;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool> (nums.size(), false);
        findPermut(nums);
        return res;
    }

private:
    void findPermut(vector<int> nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = true;
            findPermut(nums);
            used[i] = false;
            cur.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        genParen(n, 0, 0, "");
        return res;
    }
private:
    void genParen(int n, int open, int close, string cur){
        if(close == n && open == n){
            res.push_back(cur);
            return;
        }

        if(open < n){
            genParen(n, open + 1, close, cur + "(");
        }
        if(open > close){
            genParen(n, open, close + 1, cur + ")");
        }
    }
};