#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> res;
        while(left <= right && top <= bottom){
            //traverse the top row
            for(int j = left; j <= right && top <= bottom; j++){
                res.push_back(matrix[top][j]);
            }
            top++;

            //traverse the last col
            for(int i = top; i <= bottom && left <= right; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            //traverse the bottom row
            for(int j = right; j >= left && top <= bottom; j--){
                res.push_back(matrix[bottom][j]);
            }
            bottom--;

            for(int i = bottom; i >= top && left <= right; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};