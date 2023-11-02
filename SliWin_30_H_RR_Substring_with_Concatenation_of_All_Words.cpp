#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || s.size() < words.size()*words[0].size()){
            return {};
        }
        int n = words.size();
        int wordLen = words[0].size();
        int concatLen = n*wordLen;
        unordered_map<string, int> count;
        vector<int> res;
        for(string s:words){
            count[s]++;
        }

        for(int i = 0; i < wordLen; i++){
            int l = i, r = i;
            unordered_map<string, int> winCount;
            while(r + wordLen <= s.size()){
                string rightWord = s.substr(r, wordLen);
                r += wordLen;
                winCount[rightWord]++;

                while(winCount[rightWord] > count[rightWord]){
                    string leftWord = s.substr(l, wordLen);
                    l += wordLen;
                    winCount[leftWord]--;
                }

                if(r - l == concatLen){
                    res.push_back(l);
                }
            }
        }
        return res;
    }
};