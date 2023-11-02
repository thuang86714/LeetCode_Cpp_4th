#include <cstddef>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }else if(root == q){
            return q;
        }else if(root == p){
            return p;
        }

        TreeNode *R = lowestCommonAncestor(root->right, p, q);
        TreeNode *L = lowestCommonAncestor(root->left, p, q);

        if(!R && L){
            return L;
        }else if(R && !L){
            return R;
        }else if(!R && !L){
            return NULL;
        }else{
            return root;
        }
    }
};