#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    vector<double> res;
    unordered_map<string, vector<pair<string, double>>> map;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildMap(equations, values);
        
        for(auto &q:queries){
            unordered_set<string> visited(map.size());
            double ans = findFloat(q[0], q[1], visited);
            res.push_back(ans);
        }
        return res;
    }
private:
    void buildMap(vector<vector<string>>& equations, vector<double>& values){
        for(int i = 0; i < equations.size(); i++){
            map[equations[i][0]].push_back({equations[i][1], values[i]});
            map[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        return;
    }
    double findFloat(string start, string end, unordered_set<string> &visited){
        if(map.find(start) == map.end() || map.find(end) == map.end()){
            return -1;
        }

        if(start == end){
            return 1;
        }

        for(auto &next:map[start]){
            if(visited.count(next.first)){
                continue;
            }
            visited.insert(next.first);
            double res = findFloat(next.first, end, visited);
            if(res != -1){
                return res*next.second;
            }
        }
        return -1;
    }
};