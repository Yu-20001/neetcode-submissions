/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        if(root == nullptr) return 0;
        else{
            int left_max = maxDepth(root->left);
            int right_max = maxDepth(root->right);
            max = (left_max > right_max) ? left_max + 1: right_max + 1;
        }
        return max;
    }
};
