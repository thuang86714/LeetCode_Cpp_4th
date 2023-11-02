#include <vector>
using namespace std;


class Solution {
public:
    vector<pair<int, int>> dir{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                FindAdjacent(0, j, board);
            }
            if(board[m - 1][j] == 'O'){
                FindAdjacent(m - 1, j, board);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                FindAdjacent(i, 0, board);
            }
            if(board[i][n - 1] == 'O'){
                FindAdjacent(i, n - 1, board);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '#'){
                    board[i][j] = 'X';
                }else{
                    board[i][j] = 'O';
                }
            }
        }

        
    }

    void FindAdjacent(int i, int j, vector<vector<char>> &board){
        //base case
        if(board[i][j] != 'O'){
            return;
        }

        board[i][j] = '#';

        for(int k = 0; k < dir.size(); k++){
            int next_i = i + dir[k].first;
            int next_j = j + dir[k].second;
            if(next_i >= 0 && next_i < board.size() && next_j >= 0 && next_j < board[0].size()){
                FindAdjacent(next_i, next_j, board);
            }
        }
    }
};