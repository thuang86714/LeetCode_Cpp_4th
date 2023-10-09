#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};

        vector<vector<int>> res;
        queue<TreeNode*>q;
        q.push(root);
        bool LefttoRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();

                int idx = (LefttoRight)? i:(size - 1 - i);
                temp[idx] = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            LefttoRight = !LefttoRight;
            res.push_back(temp);
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int depth){
        if(!root)return;

        if(depth >= res.size())res.push_back({});

        if(depth % 2 == 0) {
                res[depth].push_back(root->val);
            } else {
                res[depth].insert(res[depth].begin(), root->val);
        }

        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
};