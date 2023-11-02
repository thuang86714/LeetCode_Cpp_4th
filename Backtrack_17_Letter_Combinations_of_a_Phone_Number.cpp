#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> dict {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string cur = "";
        findCombo(digits, 0, cur);
        return res;
    }
private:
    void findCombo(string &digits, int idx, string &cur){
        if(idx == digits.size()){
            res.push_back(cur);
            return;
        }

        for(char c: dict[digits[idx] - '0']){
            cur += c;
            findCombo(digits, idx + 1, cur);
            cur.pop_back();
        } 
        
    }

};