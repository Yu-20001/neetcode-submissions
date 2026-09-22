class Solution {
private:
    void multiBfs(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int cnt = -1;
        while(!q.empty()){
            cnt++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x + 1 < grid.size() && grid[x + 1][y] == 1){
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 1){
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if(y + 1 < grid[0].size() && grid[x][y + 1] == 1){
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 1){
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
            }
        }
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return max(0, cnt);
    }
};
