#include <cmath>
#include <algorithm>
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
    int MaxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findMax(root);
        return MaxSum;
    }
private:
    int findMax(TreeNode *root){
        if(!root){
            return 0;
        }
        int left_max = max(findMax(root->left), 0);
        int right_max = max(findMax(root->right), 0);
        MaxSum = max(MaxSum, left_max + root->val + right_max);
        return root->val + max(left_max, right_max);
    }
};