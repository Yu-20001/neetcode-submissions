class Solution {
private:
    bool search(vector<vector<char>>& board, int i, int j, string& word, int cnt){
        if(cnt == word.size()){
            return true;
        }
        if( i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[cnt]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = search(board, i + 1, j, word, cnt + 1) || search(board, i - 1, j, word, cnt + 1) || search(board, i, j + 1, word, cnt + 1) || search(board, i , j - 1, word, cnt + 1);
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                found = found || search(board, i, j, word, 0);
            }
        }
        return found;
    }
};
