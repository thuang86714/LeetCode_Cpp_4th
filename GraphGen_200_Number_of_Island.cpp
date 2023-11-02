#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int numIslands(vector<vector<char>>& grid){
        int island = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dir {0, 1, 0, -1, 0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while(!todo.empty()){
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for(int k = 0; k < 4; k++){
                            int r = p.first + dir[k], c = p.second + dir[k + 1];
                            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        } 
                    }
                }
            }
        }
        return island;
    }
};