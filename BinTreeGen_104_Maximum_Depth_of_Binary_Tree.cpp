#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //TC O(n), SC O(height)
        //recursion
        if(!root){
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //TC O(n), SC O(n)
        if(!root){
            return 0;
        }

        int depth = 0;
        queue<TreeNode*> todo;
        todo.push(root);

        while(!todo.empty()){
            int size = todo.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode *node = todo.front();
                todo.pop();
                if(node->left){
                    todo.push(node->left);
                }
                if(node->right){
                    todo.push(node->right);
                }
            }
        }
        return depth;
    }
};