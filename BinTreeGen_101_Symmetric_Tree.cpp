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
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
    }

    bool isEqual(TreeNode *L, TreeNode *R){
        if(!L && !R){
            return true;
        }
        if(!L || !R){
            return false;
        }
        if(L->val != R->val){
            return false;
        }

        return isEqual(L->left, R->right) && isEqual(L->right, R->left);
    }
};