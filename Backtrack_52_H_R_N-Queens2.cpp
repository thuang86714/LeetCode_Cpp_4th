#include <vector>
using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        //credit to jacklee20499, TC O(n^2), SC O(n)
        vector<bool> col(n, false), diag(2*n, false), anti_diag(2*n, false);
        return countQueen(n, 0, col, diag, anti_diag);
    }
private:
    int countQueen(int &n, int y, vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag){
        if(y == n){
            return 1;
        }

        int count = 0;
        for(int x = 0; x < n; x++){
            if(col[x] || diag[x + y] || anti_diag[x - y + n - 1]){
                continue;
            }
            col[x] = diag[x + y] = anti_diag[x - y + n - 1] = true;
            count += countQueen(n, y + 1, col, diag, anti_diag);
            col[x] = diag[x + y] = anti_diag[x - y + n - 1] = false;
        }
        return count;
    }
};