#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return FindLeaf(grid, 0, 0, grid.size());
    }

    Node* FindLeaf(vector<vector<int>>& grid, int i, int j, int width){
        if(allSame(grid, i, j, width)){
            return new Node(grid[i][j], true);
        }

        Node *node = new Node(true, false);
        node->topLeft = FindLeaf(grid, i, j, width/2);
        node->topRight = FindLeaf(grid, i, j + width/2, width/2);
        node->bottomLeft = FindLeaf(grid, i + width/2, j, width/2);
        node->bottomRight = FindLeaf(grid, i + width/2, j + width/2, width/2);
        return node;
    }

    bool allSame(vector<vector<int>>& grid, int i, int j, int width){
        for(int x = i; x < i + width; x++){
            for(int y = j; y < j + width; y++){
                if(grid[x][y] != grid[i][j])return false;
            }
        }
        return true;
    }
};