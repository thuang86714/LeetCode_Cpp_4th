#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(inBoard(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool inBoard(vector<vector<char>>& board, string word, int x, int y, int idx){
        if(board[x][y] != word[idx]){
            return false;
        }

        if(idx == word.size() - 1){
            return true;
        }

        bool res = false;
        char temp = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < dir.size(); i++){
            int curX = x + dir[i].first;
            int curY = y + dir[i].second;
            if(curX < 0 || curX >= board.size() || curY < 0 || curY >= board[0].size()){
                continue;
            }
            res |= inBoard(board, word, curX, curY, idx+1);
        }
        board[x][y] = temp;
        return res;
    }
};