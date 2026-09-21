class Solution {
private:
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int , int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x + 1 < grid.size() && grid[x + 1][y] == 2147483647){
                    grid[x + 1][y] = grid[x][y] + 1;
                    q.push({x + 1, y});
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 2147483647){
                    grid[x - 1][y] = grid[x][y] + 1;
                    q.push({x - 1, y});
                }
                if(y + 1 < grid[0].size() && grid[x][y + 1] == 2147483647){
                    grid[x][y + 1] = grid[x][y] + 1;
                    q.push({x, y + 1});
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 2147483647){
                    grid[x][y - 1] = grid[x][y] + 1;
                    q.push({x, y - 1});
                }
            }
        }
    }
};
