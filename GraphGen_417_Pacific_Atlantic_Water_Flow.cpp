#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //BFS, credit to jacklee20499, TC O(m*n), SC O(m*n)
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> pacific, atlantic;
        //pair<int, int> not hashable

        //find the pacific set
        for(int j = 0; j < n; j++){
            pacific.push({0, j});
        } 
        for(int i = 0; i < m; i++){
            pacific.push({i, 0});
        }
        set<pair<int, int>> pacificSet = buildSet(pacific, heights);

        //find the atlantic set
        for(int j = 0; j < n; j++){
            atlantic.push({m - 1, j});
        }
        for(int i = 0; i < m; i++){
            atlantic.push({i, n - 1});
        }
        set<pair<int, int>> atlanticSet = buildSet(atlantic, heights);
 
        vector<vector<int>> ans;
        for(auto &p: pacificSet){
            if(atlanticSet.count(p)){
                ans.push_back({p.first, p.second});
            }
        }

        return ans;
    }
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set<pair<int, int>> buildSet(queue<pair<int, int>> &oceanQ, vector<vector<int>>& heights){
        set<pair<int, int>> visited;
        
        while(!oceanQ.empty()){
            int curX = oceanQ.front().first;
            int curY = oceanQ.front().second;
            oceanQ.pop();

            visited.insert({curX, curY});

            for(int i = 0; i < dir.size(); i++){
                int nextX = curX + dir[i].first;
                int nextY = curY + dir[i].second;

                if(nextX < 0 || nextX >= heights.size() || nextY < 0 || nextY >= heights[0].size()){
                    continue;
                }

                if(visited.count({nextX, nextY}) || heights[nextX][nextY] < heights[curX][curY]){
                    continue;
                }
                oceanQ.push({nextX, nextY});
            }
        }
        return visited;
    }
};


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //DFS, credit to jacklee20499, TC O(m*n), SC O(m*n)
        int m = heights.size(), n = heights[0].size();
        set<pair<int, int>> pacific, atlantic;
        //pair<int, int> not hashable

        //find the pacific set
        for(int j = 0; j < n; j++){
            findWaytoPeak(0, j, pacific, heights);
        } 
        for(int i = 0; i < m; i++){
            findWaytoPeak(i, 0, pacific, heights);
        }

        //find the atlantic set
        for(int j = 0; j < n; j++){
            findWaytoPeak(m - 1, j, atlantic, heights);
        }
        for(int i = 0; i < m; i++){
            findWaytoPeak(i, n - 1, atlantic, heights);
        }

        vector<vector<int>> ans;
        for(auto &p: pacific){
            if(atlantic.count(p)){
                ans.push_back({p.first, p.second});
            }
        }

        return ans;
    }
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void findWaytoPeak(int x, int y, set<pair<int, int>> &ways, vector<vector<int>>& heights){
        if(ways.count({x, y})){
            return;
        }

        ways.insert({x, y});

        for(int i = 0; i < dir.size(); i++){
            int nextX = x + dir[i].first;
            int nextY = y + dir[i].second;

            if(nextX < 0 || nextX >= heights.size() || nextY < 0 || nextY >= heights[0].size()){
                continue;
            }

            if(ways.count({nextX, nextY}) || heights[nextX][nextY] < heights[x][y]){
                continue;
            }
            findWaytoPeak(nextX, nextY, ways, heights);
        }
    }
};