#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), size = 0;
        vector<int> memo(n);

        int topLeft;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = memo[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    memo[j] = matrix[i][j] - '0';
                }else{
                    memo[j] = 1 + min(topLeft, min(memo[j], memo[j - 1]));
                }
                topLeft = temp;
                size = max(size, memo[j]);
            }
        }

        return size*size;
    }
};