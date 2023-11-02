#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //BFS
        /*
        Time complexity: O(v+e)
        Space complexity: O(v+e)
        */
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> inDegree = calInDegree(numCourses, prerequisites);
        queue<int> zeroDegree;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while(!zeroDegree.empty()){
            int len = zeroDegree.size();
            for(int i = 0; i < len; i++){
                int cur = zeroDegree.front();
                zeroDegree.pop();

                for(int n:graph[cur]){
                    inDegree[n]--;
                    if(inDegree[n] == 0){
                        numCourses--;
                        zeroDegree.push(n);
                    }
                }
            }
        }

        return numCourses == 0;
    }
private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& preReq){
        vector<vector<int>> graph(numCourses);
        for(auto &p:preReq){
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }

    vector<int> calInDegree(int numCourses, vector<vector<int>>& preReq){
        vector<int> inDegree(numCourses);
        for(auto &p:preReq){
            inDegree[p[0]]++;
        }

        return inDegree;
    }
};


class Solution {
    //DFS, TLE
    /*
        Time complexity: O(v+e)
        Space complexity: O(v+e)
        */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> samePath(numCourses, false);
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        for(int i = 0; i < numCourses; i++){
            if(!traverse(i, graph, visited, samePath)){
                return false;
            }
        }

        return true;
    }
private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& preReq){
        vector<vector<int>> graph(numCourses);
        for(auto &p:preReq){
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }

    bool traverse(int cur, vector<vector<int>>& graph, vector<bool> visited, vector<bool> &samePath){
        if(samePath[cur]){
            return false;
        }

        if(visited[cur]){
            return true;
        }

        samePath[cur] = true;
        visited[cur] = true;

        for(int node: graph[cur]){
            if(!traverse(node, graph, visited, samePath)){
                return false;
            }
        }

        samePath[cur] = false;
        return true;
    }
};