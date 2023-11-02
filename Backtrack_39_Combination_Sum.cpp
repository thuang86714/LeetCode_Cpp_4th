#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        findCombo(candidates, target, cur, 0);
        return res;
    }
private:
    void findCombo(vector<int>& candidates, int target, vector<int> &cur, int idx){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target < 0 || idx == candidates.size()){
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            findCombo(candidates, target - candidates[i], cur, i);
            cur.pop_back();
        }
    }
};