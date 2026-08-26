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
    int max_diameter = 0;
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int left_depth = getDepth(node->left);
        int right_depth = getDepth(node->right);
        max_diameter = max(max_diameter, left_depth + right_depth);
        return 1 + max(left_depth, right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return max_diameter;
    }
};