class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!curr->children[c - 'a']){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
            if(i == word.size() - 1) curr->isEnd = true;
        }
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr->children[word[i] - 'a']) return false;
            curr = curr->children[word[i] - 'a'];
        }
        if(curr->isEnd) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!curr->children[prefix[i] - 'a']) return false;
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};
