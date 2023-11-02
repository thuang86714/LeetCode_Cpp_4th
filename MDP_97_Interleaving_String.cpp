#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        int m = s1.size(), n = s2.size();

        vector<bool> memo(n + 1, false);

        memo[0] = true;

        for(int j = 1; j <= n; j++){
            memo[j] = s2[j - 1] == s3[j - 1] && memo[j - 1];
        }

        for(int i = 1; i <= m; i++){
            memo[0] = s3[i - 1] == s1[i - 1] && memo[0];
            for(int j = 1; j <= n; j++){
                memo[j] = (s3[i + j - 1] == s1[i - 1] && memo[j]) || (s3[i + j - 1] == s2[j - 1] && memo[j - 1]);
            }
        }
        return memo[n];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        int m = s1.size(), n = s2.size();

        vector<vector<bool>> memo(m + 1, vector<bool> (n + 1, false));

        memo[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s1[i - 1] == s3[i - 1] && memo[i - 1][0]){
                memo[i][0] = true;
            }
        }

        for(int j = 1; j <= n; j++){
            if(s2[j - 1] == s3[j - 1] && memo[0][j - 1]){
                memo[0][j] = true;
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if((s3[i + j - 1] == s1[i - 1] && memo[i - 1][j]) || (s3[i + j - 1] == s2[j - 1] && memo[i][j - 1])){
                    memo[i][j] = true;
                }
            }
        }
        return memo[m][n];
    }
};