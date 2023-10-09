#include <vector>
#include <cstddef>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildSubBST(nums, 0, nums.size()-1);
    }

    TreeNode* buildSubBST(vector<int>& nums, int start, int end){
        if(start > end)return NULL;

        int mid = (start + end)/2;

        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildSubBST(nums, start, mid -1);
        node->right = buildSubBST(nums, mid+1, end);

        return node;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //base case
        if(nums.size() == 0)return NULL;
        //recursion

        int n = nums.size();
        TreeNode *root = new TreeNode(nums[n/2]);
        vector<int> left, right;
        for(int i = 0; i < n/2; i++){
            left.push_back(nums[i]);
        }
        for(int i = n/2+1; i < n; i++){
            right.push_back(nums[i]);
        }

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};