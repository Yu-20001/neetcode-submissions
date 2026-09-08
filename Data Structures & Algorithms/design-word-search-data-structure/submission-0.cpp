class WordDictionary {
private:
    struct DictNode{
        DictNode* children[26];
        bool isEnd;

        DictNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    DictNode* root;
public:
    WordDictionary() {
        root = new DictNode();
    }
    
    void addWord(string word) {
        DictNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(!curr->children[idx]){
                curr->children[idx] = new DictNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    bool dfs(DictNode* node, string& word, int i){
        if(i == word.size()) return node->isEnd;
        if(word[i] != '.'){
            int idx = word[i] - 'a';
            if(!node->children[idx]) return false;
            else return dfs(node->children[idx], word, i+1);
        }
        for(int j = 0; j < 26; j++){
            if(node->children[j] && dfs(node->children[j], word, i+1)) return true; 
        }
        return false;
        
    }
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
