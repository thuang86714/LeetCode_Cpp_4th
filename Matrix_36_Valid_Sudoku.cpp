#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> sqr(9), row(9), col(9);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int d = i/3*3 + j/3;
                    if(!row[i].emplace(num).second){
                        return false;
                    }
                    if(!col[j].emplace(num).second){
                        return false;
                    }
                    if(!sqr[d].emplace(num).second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
