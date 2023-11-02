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
    TreeNode *prev;
    int diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        findAbsDiff(root);
        return diff;
    }
private:
    void findAbsDiff(TreeNode *root){
        if(!root){
            return;
        }

        findAbsDiff(root->left);

        if(prev){
            diff = min(diff, root->val - prev->val);
        }

        prev = root;
        findAbsDiff(root->right);
    }
};