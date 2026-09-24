class Solution {
private:
    void multiBfs(vector<vector<bool>>& bound, vector<vector<char>>& board){
        int r = board.size();
        int c = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(bound[i][j]){
                    q.push({i, j});
                    board[i][j] = 'T';
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x + 1 < board.size() && board[x + 1][y] == 'O'){
                    board[x + 1][y] = 'T';
                    q.push({x + 1, y});
                }
                if(x - 1 >= 0 && board[x - 1][y] == 'O'){
                    board[x - 1][y] = 'T';
                    q.push({x - 1, y});
                }
                if(y + 1 < board[0].size() && board[x][y + 1] == 'O'){
                    board[x][y + 1] = 'T';
                    q.push({x, y + 1});
                }
                if(y - 1 >= 0 && board[x][y - 1] == 'O'){
                    board[x][y - 1] = 'T';
                    q.push({x, y - 1});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> bound(r, vector<bool>(c, false));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'O' && (i == 0 || i == r - 1 || j == 0 || j == c - 1)){
                    bound[i][j] = true;
                }
            }
        }

        multiBfs(bound, board);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
                else continue;
            }
        }
    }
};
