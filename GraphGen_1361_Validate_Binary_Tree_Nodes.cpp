#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //BFS
        //TC O(n), SC O(n)
        //cycle-->false
        //have multiple parents-->false
        
        //step 1 buildGraph
        //haveMultiPare()-->indegree
        //step 2 DFS traverse func
        //hasCycle()

        buildGraph(leftChild, rightChild);
        vector<int> inComingDegree(n, 0);
        if(!calIncomingDegree(inComingDegree)){
            return false;
        }

        while(!zeroDegree.empty()){
            int len = zeroDegree.size();
            for(int j = 0; j < len; j++){
                int node = zeroDegree.front();
                zeroDegree.pop();
                n--;
                for(int &adj:graph[node]){
                    inComingDegree[adj]--;
                    if(inComingDegree[adj] == 0){
                        zeroDegree.push(adj);
                    }
                }
            }
        }

        return n == 0;
    }
private:
    unordered_map<int, vector<int>> graph;
    queue<int> zeroDegree;
    void buildGraph(vector<int>& leftChild, vector<int>& rightChild){
        for(int i = 0; i < leftChild.size(); i++){
            if(leftChild[i] != -1){
                graph[i].push_back(leftChild[i]);
            }
            if(rightChild[i] != -1){
                graph[i].push_back(rightChild[i]);
            }
        }
    }

    bool calIncomingDegree(vector<int> &inComingDegree){//cal incoming degree and make sure there's only one tree
        for(auto &node: graph){
            for(auto &to:node.second){
                inComingDegree[to]++;
            }
        }
        int counter = 0;
        for(int i = 0; i < inComingDegree.size(); i++){
            if(inComingDegree[i] > 1){
                return false;
            }
            if(inComingDegree[i] == 0){//root's indegree == 0
                counter++;
                zeroDegree.push(i);
            }
        }
        if(counter == 1){
            return true;
        }else{
            return false;
        }
    }

};


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //DFS
        //TC O(n), SC O(n)
        //cycle-->false
        //have multiple parents-->false
        
        //step 1 buildGraph
        //haveMultiPare()-->indegree
        //step 2 DFS traverse func
        //hasCycle()

        buildGraph(leftChild, rightChild);
        vector<int> incomingDegree(n, 0);
        if(!calIncomingDegree(incomingDegree)){
            return false;
        }
        
        vector<bool> visited(n, false);
        vector<bool> samePath(n, false);
        for(int i = 0; i < n; i++){
            if(!validateNoCycle(i, visited, samePath)){
                return false;
            }
        }

        return true;
    }
private:
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<int>& leftChild, vector<int>& rightChild){
        for(int i = 0; i < leftChild.size(); i++){
            if(leftChild[i] != -1){
                graph[i].push_back(leftChild[i]);
            }
            if(rightChild[i] != -1){
                graph[i].push_back(rightChild[i]);
            }
        }
    }

    bool calIncomingDegree(vector<int> &inDegree){//cal incoming degree and make sure there's only one tree
        for(auto &node: graph){
            for(auto &to:node.second){
                inDegree[to]++;
            }
        }
        int counter = 0;
        for(auto &degree:inDegree){
            if(degree > 1){
                return false;
            }
            if(degree == 0){//root's indegree == 0
                counter++;
            }
        }
        if(counter == 1){
            return true;
        }else{
            return false;
        }
    }

    bool validateNoCycle(int node, vector<bool> &visited, vector<bool> &samePath){
        if(samePath[node]){
            return false;
        }

        if(visited[node]){
            return true;
        }

        samePath[node] = true;
        visited[node] = true;

        for(auto &next:graph[node]){
            if(!validateNoCycle(next, visited, samePath)){
                return false;
            }
        }

        samePath[node] = false;
        return true;
    }
};