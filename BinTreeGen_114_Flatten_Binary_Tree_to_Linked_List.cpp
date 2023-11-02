#include <cstddef>



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
    void flatten(TreeNode* root) {
        TreeNode *node = root;
        while(node){
            if(node->left){
                TreeNode *L = node->left;
                while(L->right){
                    L = L->right;
                }
                L->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};