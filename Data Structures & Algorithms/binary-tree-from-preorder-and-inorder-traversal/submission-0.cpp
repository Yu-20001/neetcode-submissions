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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int it = 0;
        while(inorder[it] != preorder[0]){
            it++;
        }
        vector<int> l_pre(it);
        vector<int> l_in(it);
        vector<int> r_pre(preorder.size() - 1 - it);
        vector<int> r_in(preorder.size() - 1 - it);

        for(int i = 1; i < preorder.size(); i++){
            if(i <= it) l_pre[i - 1] = preorder[i];
            else{
                r_pre[i-1-it] = preorder[i];
            }
        }
        
        for(int i = 0; i < inorder.size(); i++){
            if(i < it) l_in[i] = inorder[i];
            else if(i == it) continue;
            else{
                r_in[i-it-1] = inorder[i];
            }
        }
    

        root->left = buildTree(l_pre, l_in);
        root->right = buildTree(r_pre, r_in);
        return root;
    }
};
