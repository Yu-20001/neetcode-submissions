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
    int cnt(TreeNode* node, int curMax){
        int good = 0;
        if(node == nullptr) return 0;
        good = (node->val >= curMax) ? 1 : 0;
        int newMax = max(node->val, curMax);
        return good + cnt(node->left, newMax) + cnt(node->right, newMax);
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return cnt(root, root->val);
    }
};
