#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        findCombo(n, k, 1, combo);
        return res;
    }

private:
    void findCombo(int n, int k, int start, vector<int> &combo){
        if(combo.size() == k){
            res.push_back(combo);
            return;
        }

        for(int i = start; i <= n; i++){
            combo.push_back(i);
            findCombo(n, k, i + 1, combo);
            combo.pop_back();
        }
    }
};