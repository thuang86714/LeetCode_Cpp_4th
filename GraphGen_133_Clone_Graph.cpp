#include <vector>
#include <unordered_map>
#include <queue>
using namespace  std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        //BFS
        unordered_map<Node*, Node*>map;
        Node *clone = new Node(node->val);
        map[node] = clone;
        queue<Node*> toCopy;
        toCopy.push(node);

        while(!toCopy.empty()){
            int len = toCopy.size();
            for(int i = 0; i < len; i++){
                Node *cur = toCopy.front();
                toCopy.pop();
                for(auto &nei:cur->neighbors){
                    if(map.find(nei) == map.end()){
                        Node *copy = new Node(nei->val);
                        map[nei] = copy;
                        toCopy.push(nei);
                    }
                    map[cur]->neighbors.push_back(map[nei]);
                }
            }
        }
        return map[node];
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> map;
    //DFS
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        Node *clone = new Node(node->val);
        if(node->neighbors.empty()){
            return clone;
        }
        map[node] = clone;

        vector<Node*> cloneVec;
        for(auto &nei:node->neighbors){
            if(map.find(nei) == map.end()){
                Node *newNei = cloneGraph(nei);
                cloneVec.push_back(newNei);
            }else{
                cloneVec.push_back(map[nei]);
            }
        }
        clone->neighbors = cloneVec;

        return clone;

    }
};