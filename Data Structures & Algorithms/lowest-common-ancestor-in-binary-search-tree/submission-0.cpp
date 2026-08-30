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
    TreeNode* rt;
    stack<TreeNode*> findPath(TreeNode* node){
        TreeNode* curr = rt;
        stack<TreeNode*> rev_st;
        stack<TreeNode*> st;
        while(curr->val != node->val){
            rev_st.push(curr);
            if(curr->val > node->val){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        rev_st.push(node);
        while(!rev_st.empty()){
            TreeNode* tmp = rev_st.top();
            rev_st.pop();
            st.push(tmp);
        }
        return st;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rt = root;
        stack<TreeNode*> st1, st2;
        st1 = findPath(p);
        st2 = findPath(q);
        TreeNode* tmp;
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top()){
            tmp = st1.top();
            st1.pop();
            st2.pop();
        }
        return tmp;
    }
};
