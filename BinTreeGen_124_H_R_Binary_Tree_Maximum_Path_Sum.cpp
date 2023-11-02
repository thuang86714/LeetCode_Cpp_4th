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
    //credit to Leodicap99, TC O(n), SC O(n)
public:
    int MaxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        GetMax(root);
        return MaxSum;
    }
private:
    int GetMax(TreeNode *node){
        //base case
        if(!node){
            return 0;
        }

        int left = max(GetMax(node->left), 0);
        int right = max(GetMax(node->right), 0);

        MaxSum = max(MaxSum, node->val + left + right);

        return node->val + max(left, right);
    }
};