/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 
Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/
#include <cstddef>
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
    //credit to Leodicap99, TC O(n), n is the num of node in a tree, SC O(logn)
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }

    int maxGain(TreeNode* root){
        //base case
        if(!root)return 0;
        //then do post-order traversal
        int l = max(maxGain(root->left), 0);
        int r = max(maxGain(root->right), 0);

        int new_sum = root->val + r + l;
        max_sum = max(max_sum, new_sum);
        return root->val + max(l, r);
    }
};