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
    bool isValid(TreeNode* node, int lower, int upper){
        if(node == nullptr) return true;
        if(node->val <= lower || node->val >= upper )return false;
        return isValid(node->left, lower, node->val) && isValid(node->right, node->val, upper);
    }
    bool isValidBST(TreeNode* root) {
       if(root == nullptr) return true;
       return isValid(root, INT_MIN, INT_MAX);
    }
};
