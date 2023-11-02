#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //theoritically, SC could be O(1)
        int n = word1.size(), m = word2.size();

        vector<int> memo(m + 1, 0);

        //base case
        for(int j = 1; j <= m; j++){
            memo[j] = j;
        }
        
        int topLeft;

        for(int i = 1; i <= n; i++){
            topLeft = memo[0];
            memo[0] = i;
            for(int j = 1; j <= m; j++){
                int temp = memo[j];
                if(word1[i - 1] == word2[j - 1]){
                    memo[j] = topLeft;
                }else{
                    memo[j] = min(topLeft, min(memo[j], memo[j - 1])) + 1;
                }
                topLeft = temp;
            }
        }

        return memo.back();
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

        //base case
        for(int j = 1; j <= m; j++){
            memo[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            memo[i][0] = i;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    memo[i][j] = memo[i - 1][j - 1];
                }else{
                    memo[i][j] = min(memo[i - 1][j - 1], min(memo[i - 1][j], memo[i][j - 1])) + 1;
                }
            }
        }

        return memo[n][m];
    }
};