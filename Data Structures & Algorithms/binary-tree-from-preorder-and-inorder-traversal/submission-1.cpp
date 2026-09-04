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
    int preIdx = 0;
    unordered_map<int, int> inIndex;
    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        int mid = inIndex[rootVal];
        TreeNode* node = new TreeNode(rootVal);
        node->left = build(preorder, left, mid - 1);
        node->right = build(preorder, mid + 1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1);
    }
};
