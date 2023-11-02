#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};
        int size = s.size();
        vector<bool> memo(size + 1, false);
        memo[0] = true;
        for(int i = 1; i <= size; i++){
            for(int j = i - 1; j >= 0; j--){
                if(dict.count(s.substr(j, i - j)) && memo[j]){
                    memo[i] = true;
                    break;
                }
            }
        }

        return memo.back();
    }
};