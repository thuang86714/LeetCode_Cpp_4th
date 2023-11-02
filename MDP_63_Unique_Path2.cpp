#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> memo(n, 0);

        //traverse the first row
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j]){
                break;
            }
            memo[j] = 1;
        }

        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0]|| !memo[0]){
                memo[0] = 0;
            }
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]){
                    memo[j] = 0;
                }else{
                    memo[j] += memo[j - 1]; 
                }
            }
        }

        return memo.back();
    }
};