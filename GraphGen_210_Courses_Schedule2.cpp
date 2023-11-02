#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //BFS
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> inDegree = calInDegree(numCourses, prerequisites);
        queue<int> zeroDegree;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                ans.push_back(i);
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while(!zeroDegree.empty()){
            int len = zeroDegree.size();

            for(int i = 0; i < len; i++){
                int cur = zeroDegree.front();
                zeroDegree.pop();

                reduceDegree(cur, numCourses, graph, inDegree, zeroDegree);
            }
        }


        if(numCourses == 0){
            return ans;
        }else{
            return {};
        }
    }
private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto &p:prerequisites){
            int from = p[1], to = p[0];
            graph[from].push_back(to);
        }
        return graph;
    }

    vector<int> calInDegree(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> inDegree(numCourses);

        for(auto &p:prerequisites){
            inDegree[p[0]]++;
        }

        return inDegree;
    }

    void reduceDegree(int cur, int &numCourses, vector<vector<int>>& graph, vector<int> &inDegree, queue<int> &zeroDegree){
        for(int next:graph[cur]){
            inDegree[next]--;
            if(inDegree[next] == 0){
                ans.push_back(next);
                zeroDegree.push(next);
                numCourses--;
            }
        }

        return;
    }
};


class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //DFS
        
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses);
        vector<bool> samePath(numCourses);

        for(int i = 0; i < numCourses; i++){
            if(!traverse(i, graph, visited, samePath)){
                return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto &p:prerequisites){
            int from = p[1], to = p[0];
            graph[from].push_back(to);
        }
        return graph;
    }

    bool traverse(int cur, vector<vector<int>>& graph, vector<bool> &visited, vector<bool> &samePath){
        if(samePath[cur]){
            return false;
        }

        if(visited[cur]){
            return true;
        }

        samePath[cur] = true;
        visited[cur] = true;

        for(int &to:graph[cur]){
            if(!traverse(to, graph, visited, samePath)){
                return false;
            }
        }

        ans.push_back(cur);
        samePath[cur] = false;

        return true;
    }
};

