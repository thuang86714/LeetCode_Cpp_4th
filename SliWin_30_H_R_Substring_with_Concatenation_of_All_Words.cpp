#include <unordered_map>
#include <deque>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //credit to jacklee20499, TC O(m*n), SC O(m), where n is length of s, m is length of words
        //edge case
        if(s.size() < words.size()*words[0].size()){
            return {};
        }

        int wordLen = words[0].size();
        int concatLen = wordLen*words.size();
        vector<int> ans;
        unordered_map<string, int> wordCount;
        for(string &s:words){
            wordCount[s]++;
        }

        for(int i = 0; i < wordLen; i++){
            int l = i, r = i;
            unordered_map<string, int> windowCount;
            deque<string> dq;

            while(r + wordLen <= s.size()){
                string RightWord = s.substr(r, wordLen);
                r += wordLen;
                dq.push_back(RightWord);
                windowCount[RightWord]++;

                while(windowCount[RightWord] > wordCount[RightWord]){
                    string LeftWord = dq.front();
                    dq.pop_front();
                    l += wordLen;
                    windowCount[LeftWord]--;
                }

                if(r - l == concatLen){
                    ans.push_back(l);
                }
            }
        }
        return ans;
    }
};