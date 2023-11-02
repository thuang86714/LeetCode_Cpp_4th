#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2){
            return s;
        }
        int n = s.size();
        vector<vector<bool>> memo(n, vector<bool> (n, false));

        for(int i = 0; i < n; i++){
            memo[i][i] = true;
        }
        int head = n - 1, len = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    if(memo[i + 1][j - 1] || j - i == 1){
                        memo[i][j] = true;
                        if(len < j - i + 1){
                            head = i;
                            len = j - i + 1;
                        }
                    }
                }
            }
        }
        return s.substr(head, len);
    }
};