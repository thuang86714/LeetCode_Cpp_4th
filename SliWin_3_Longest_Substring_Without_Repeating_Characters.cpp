#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, l = 0, r = 0;
        unordered_set<int> dict;
        while(r < s.size()){
            if(!dict.count(s[r])){
                dict.insert(s[r]);
                len = max(len, r - l + 1);
                r++;
            }else{
                dict.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};