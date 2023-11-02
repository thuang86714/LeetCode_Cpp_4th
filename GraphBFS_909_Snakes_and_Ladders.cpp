#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        //BFS
        int n = board.size();
        int label = 1;
        vector<pair<int, int>> cell(n*n+1);
        vector<int> cols(n);
        for(int i = 0; i < n; i++){
            cols[i] = i;
        }

        for(int row = n - 1; row >= 0; row--){
            for(int col:cols){
                cell[label++] = {row, col};
            }
            reverse(cols.begin(), cols.end());
        }

        queue<int> toVisit;
        toVisit.push(1);

        vector<int> memo(n*n+1, -1);
        memo[1] = 0;

        while(!toVisit.empty()){
            int node = toVisit.front();
            toVisit.pop();
            for(int next = node + 1; next <= min(node+6, n*n); next++){
                int r = cell[next].first;
                int c = cell[next].second;
                int dest;
                if(board[r][c] != -1){
                    dest = board[r][c];
                }else{
                    dest = next;
                }

                if(memo[dest] == -1){
                    memo[dest] = memo[node] + 1;
                    toVisit.push(dest);
                }                
            }
        }

        return memo.back();
    }
};