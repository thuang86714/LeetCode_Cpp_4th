#include <unordered_map>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //TC O(n + m), SC O(n + m)
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> temp;
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(!isalnum(s[i]))continue;

            while(i < s.size() && isalnum(s[i])){
                word.push_back(s[i]);
                i++;
            }

            temp.push_back(word);
            word = "";
        }

        if(pattern.size() != temp.size())return false;
        
        for(int i = 0; i < pattern.size(); i++){
            if(!map1.count(pattern[i]) && !map2.count(temp[i])){
                map1[pattern[i]] = temp[i];
                map2[temp[i]] = pattern[i];
            }else if(map1.count(pattern[i]) && map2.count(temp[i])){
                if(map1[pattern[i]] != temp[i] || map2[temp[i]] != pattern[i])return false;
            }else{
                return false;
            }
        }
        return true;
    }
};