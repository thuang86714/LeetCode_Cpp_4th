#include <vector>
using namespace std;


class Solution {
public:
    vector<pair<int, int>>dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int island = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    findAdjacent(grid, i, j);
                }
            }
        }
        return island;
    }

    void findAdjacent(vector<vector<char>>& grid, int i, int j){
        //base case
        if(grid[i][j] != '1')return;

        grid[i][j] = '#';

        for(int k = 0; k < 4; k++){
            auto newI = i + dir[k].first;
            auto newJ = j + dir[k].second;

            if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size())continue;
            findAdjacent(grid, newI, newJ);
        }
    }
};