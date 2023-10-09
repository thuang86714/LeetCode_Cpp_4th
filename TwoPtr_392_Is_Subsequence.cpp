#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //edge case s.size() > t.size()-->return false
        int len = s.size(), count = s.size();
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[len - count])count--;
        }
        return count == 0;
    }
};