#include <string>
#include <cctype>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size()-1;
        
        while(i >= 0 && !isalpha(s[i])){
            i--;
        }

        while(i >= 0 && isalpha(s[i])){
            i--;
            count++;
        }
        return count;
        
    }
};