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
    int maxVal = INT_MIN;
    int pathSum(TreeNode* node){
        if(!node) return 0;
        int l = 0;
        int r = 0;
        if(node->left) l = max(0, pathSum(node->left));
        if(node->right) r = max(0, pathSum(node->right));
        int tmp = node->val + l + r;
        maxVal = max(maxVal, tmp);
        int p = node->val + max(l, r);
        return p;
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxVal;
    }
};
