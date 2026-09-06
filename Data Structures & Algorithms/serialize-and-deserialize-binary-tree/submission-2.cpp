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

class Codec {
public:
    string code = "";
    void encode(TreeNode* root){
        if(!root) code += "-,";
        else{
            code += to_string(root->val) + ",";
            encode(root->left);
            encode(root->right);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        code = "";
        encode(root);
        return code;
    }
    vector<string> toToken(string data){
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int decodeIdx = 0;
    TreeNode* decode(const vector<string>& tokens){
        string currentToken = tokens[decodeIdx++];
        if(currentToken == "-") return nullptr;
        int currentVal = stoi(currentToken);
        TreeNode* newNode = new TreeNode(currentVal);
        newNode->left = decode(tokens);
        newNode->right = decode(tokens);
        return newNode;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        decodeIdx = 0;
        vector<string> tokens = toToken(data);
        return decode(tokens);
    }
};
