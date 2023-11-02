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
    int sumNumbers(TreeNode* root) {
        return findSum(root, 0);
    }

private:
    int findSum(TreeNode* root, int sum){
        //base case
        if(!root){
            return 0;
        }
        sum = 10*sum + root->val;
        if(!root->left &&!root->right){
            return sum;
        }else{
            return findSum(root->left, sum)+ findSum(root->right, sum); 
        }
    }
};