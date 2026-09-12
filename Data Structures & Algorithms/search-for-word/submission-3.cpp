class Solution {
private:
    bool found = false;
    void search(vector<vector<char>>& board, int i, int j, string& word, int cnt){
        if(cnt == word.size()) found = true;
        if( i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[cnt]) return;
        char temp = board[i][j];
        board[i][j] = '#';
        search(board, i + 1, j, word, cnt + 1);
        search(board, i - 1, j, word, cnt + 1);
        search(board, i, j + 1, word, cnt + 1);
        search(board, i, j - 1, word, cnt + 1);
        board[i][j] = temp;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                search(board, i, j, word, 0);
            }
        }
        return found;
    }
};
