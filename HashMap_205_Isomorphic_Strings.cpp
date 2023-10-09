#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1, map2;

        for(int i = 0; i < s.size(); i++){
            if(!map1.count(s[i])&& !map2.count(t[i])){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }else if(map1.count(s[i])&& map2.count(t[i])){
                if(map1[s[i]] != t[i] || map2[t[i]] != s[i])return false;
            }else{
                return false;
            }
        }
        return true;
    }
};