class Solution {
private:
    int bfs(int r, int c, vector<vector<int>>& grid){
        int area = 0;
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            area++;
            if(i + 1 < grid.size() && grid[i + 1][j] == 1){
                q.push({i + 1, j});
                grid[i + 1][j] = 0;
            }
            if(i - 1 >= 0 && grid[i - 1][j] == 1){
                q.push({i - 1, j});
                grid[i - 1][j] = 0;
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1){
                q.push({i, j + 1});
                grid[i][j + 1] = 0;
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1){
                q.push({i, j - 1});
                grid[i][j - 1] = 0;
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = bfs(i, j, grid);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
