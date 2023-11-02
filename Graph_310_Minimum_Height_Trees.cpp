#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()){
            return {0};
        }
        //credit to jacklee20499, TC O(n), SC O(n)
        //BFS-->with the same number of nodes, the wider tree is less high the the thin tree
        //the root of the widest tree have the most inDegree
        vector<vector<int>> graph = buildGraph(n, edges);
        
        calInComingDegree(graph);
        
        while(n > 2){
            int len = leaf.size();
        
            for(int i = 0; i < len; i++){
                int node = leaf.front();
                leaf.pop();
                for(int &adj:graph[node]){
                    inComingDegree[adj]--;
                    if(inComingDegree[adj] == 1){
                        leaf.push(adj);
                    }
                }
            }
            n -= len;
        }

        vector<int> ans;
        while(!leaf.empty()){
            ans.push_back(leaf.front());
            leaf.pop();
        }

        return ans;
    }
private:
    queue<int> leaf;
        vector<int> inComingDegree;
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges){
        vector<vector<int>> graph(n);
        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    void calInComingDegree(const vector<vector<int>> &graph){
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size() == 1){
                leaf.push(i);
            }
            inComingDegree.push_back(graph[i].size());
        }
    }
};


class Solution {
public:
    vector<vector<int>> G;
	vector<bool> seen;
    vector<int> dfs(int i) {
        //credit to jacklee20499, TC (n), SC O(n)
		// longestPath will hold longest path found, starting from any of adjacent nodes of i
        vector<int> longestPath, path;
        seen[i] = true;                            // mark as visited to avoid loop
        for(auto adj : G[i])                       // run DFS from each adjacent node to find longest path
            if(!seen[adj]) 
                if(size(path = dfs(adj)) > size(longestPath)) 
                    longestPath = move(path);      // avoids copying...more info below
        seen[i] = false;
		longestPath.push_back(i);                  // add i itself to longest path & we get the longest path starting at i
        return longestPath;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        G.resize(n); seen.resize(n);
        for(auto& E : edges) 
            G[E[0]].push_back(E[1]), 
            G[E[1]].push_back(E[0]);
        auto path = dfs(dfs(0)[0]);                // 1st DFS from arbitrary node(0 in this case) & another DFS from furthest node returned by 1st DFS
        if(size(path) & 1)                         // 1 mid-node when path length is odd, otherwise 2
		    return {path[size(path)/2]};           
        return {path[size(path)/2], path[size(path)/2-1]};
    }
};