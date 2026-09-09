class Solution {
private:
    struct TrieNode{
        TrieNode* children[26];
        string word;

        TrieNode(){
            word = "";
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    void build_trie(vector<string>& words){
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            TrieNode* curr = root;
            for(int j = 0; j < words[i].size(); j++){
                int idx = words[i][j] - 'a';
                if(!curr->children[idx]){
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->word = words[i];
        }
    }

    vector<string> ans;
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& ans){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#') return;
        char ch = board[r][c];

        if(!node->children[ch - 'a']) return;

        node = node->children[ch - 'a'];

        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';
        dfs(board, r+1, c, node, ans);
        dfs(board, r-1, c, node, ans);
        dfs(board, r, c+1, node, ans);
        dfs(board, r, c-1, node, ans);

        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build_trie(words);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
