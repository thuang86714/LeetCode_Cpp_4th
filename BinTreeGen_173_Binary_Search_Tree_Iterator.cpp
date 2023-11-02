#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        insert(root);
    }
    
    int next() {
        TreeNode *cur= st.top();
        st.pop();

        insert(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
    void insert(TreeNode* node){
        if(!node){
            return;
        }
        st.push(node);
        insert(node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */