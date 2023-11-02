#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false), diag(2*n, false), anti_diag(2*n, false);
        vector<string> board(n, string(n, '.'));
        placeQueen(n, 0, col, diag, anti_diag, board);
        return res;
    }

private:
    void placeQueen(int &n, int y, vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag, vector<string> &board){
        if(y == n){
            res.push_back(board);
            return;
        }

        for(int x = 0; x < n; x++){
            if(col[x] || diag[x + y] || anti_diag[x - y + n - 1]){
                continue;
            }
            col[x] = diag[x + y] = anti_diag[x - y + n - 1] = true;
            board[x][y] = 'Q';
            placeQueen(n, y + 1, col, diag, anti_diag, board);
            board[x][y] = '.';
            col[x] = diag[x + y] = anti_diag[x - y + n - 1] = false;
        }
    }
};