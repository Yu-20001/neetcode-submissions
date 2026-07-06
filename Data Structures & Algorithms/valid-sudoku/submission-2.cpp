class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0};
        bool col[9][10] = {0};
        bool grid[9][10] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = int(board[i][j] - '0');
                    if(row[i][n] || col[j][n] || grid[(i/3) * 3 + j/3][n]){
                        return false;
                    }
                    else{
                        row[i][n] = 1;
                        col[j][n] = 1;
                        grid[(i/3)*3 + j/3][n] = 1;
                    }
                }
            }
        }
        return true;
    }
};