/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9
*/

#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        //credit to karan_8082, TC O(n!*n), SC O(n^2)
        vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
        return helper(col, diag, anti_diag, 0);
    }

    int helper(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row){
        //base case
        if(row == col.size())return 1;
        int n = col.size(), count = 0;
        for(int column = 0; column < n; column++){
            //for diags--> one would be row+col is fixed, the other is r - c would be fixed
            if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){
                //anti_diag[row - column + constant to make it a uint]
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
                count += helper(col, diag, anti_diag, row + 1);
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;
            }
        }
        return count;
    }
};