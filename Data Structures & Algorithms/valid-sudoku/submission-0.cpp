class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int grid[9][10] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = int(board[i][j] - '0');
                    if(row[i][n] == 0){
                        row[i][n] = 1;
                    }
                    else{
                        return false;
                    }
                    if(col[j][n] == 0){
                        col[j][n] = 1;
                    }
                    else{
                        return false;
                    }
                    int grid_id = (i/3) * 3  + j/3;
                    if(grid[grid_id][n] == 0){
                        grid[grid_id][n] = 1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};