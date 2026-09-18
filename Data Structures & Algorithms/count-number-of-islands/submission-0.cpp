class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i + 1][j] == '1'){
                grid[i + 1][j] = '0';
                q.push({i + 1, j});
            }
            if(i - 1 >= 0 && grid[i - 1][j] == '1'){
                grid[i - 1][j] = '0';
                q.push({i - 1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == '1'){
                grid[i][j + 1] = '0';
                q.push({i, j + 1});
            }
            if(j - 1 >= 0 && grid[i][j - 1] == '1'){
                grid[i][j - 1] = '0';
                q.push({i, j - 1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
