class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
    void build(int n){
        string row = "";
        for(int i = 0; i < n; i++){
            row += '.';
        }
        for(int i = 0; i < n; i++){
            board.push_back(row);
        }
    }
    bool diagonalCheck(int row, int col, vector<string>& board){
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;
        
        while(i >= 0 && j < board.size()){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void placeQ(int n, int row, vector<bool>& used_col, vector<string>& board){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(!used_col[col] && diagonalCheck(row, col, board)){
                used_col[col] = true;
                board[row][col] = 'Q';

                placeQ(n, row + 1, used_col, board);
                
                used_col[col] = false;
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        build(n);
        vector<bool> used_col(n, false);
        placeQ(n, 0, used_col, board);
        return ans;
    }
};
