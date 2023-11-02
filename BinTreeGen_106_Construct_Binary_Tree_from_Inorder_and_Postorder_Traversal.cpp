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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        int postIdx = n;
        return buildTreeFromVector(inorder, postorder, 0, n, postIdx);
    }
private:
    TreeNode* buildTreeFromVector(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postIdx){
        //base case
        if(inStart > inEnd){
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postIdx]);
        postIdx--;

        int inIdx = inStart;
        while(inorder[inIdx] != root->val){
            inIdx++;
        }

        TreeNode *R = buildTreeFromVector(inorder, postorder, inIdx + 1, inEnd, postIdx);
        TreeNode *L = buildTreeFromVector(inorder, postorder, inStart, inIdx - 1, postIdx);
        
        root->left = L;
        root->right = R;

        return root;
    }
};