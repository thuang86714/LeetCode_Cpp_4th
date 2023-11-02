#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() - 1;
        int preIdx = 0;
        return buildTreeFromVector(preorder, inorder, 0, n, preIdx);
    }
private:
    TreeNode* buildTreeFromVector(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int &preIdx){
        //base case
        if(inStart > inEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preIdx]);
        preIdx++;

        int inIdx = inStart;
        while(inorder[inIdx] != root->val){
            inIdx++;
        }

        TreeNode *L = buildTreeFromVector(preorder, inorder, inStart, inIdx - 1, preIdx);
        TreeNode *R = buildTreeFromVector(preorder, inorder, inIdx + 1, inEnd, preIdx);

        root->left = L;
        root->right = R;

        return root;
    }
};