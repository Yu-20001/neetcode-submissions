class Solution {
private:
    void multiBfs(vector<vector<int>>& heights, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(visited[i][j]){
                    q.push({i, j});   
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                int h = heights[x][y];
                q.pop();
                if(x + 1 < heights.size() && heights[x + 1][y] >= h && visited[x + 1][y] == false){
                    visited[x + 1][y] = true;
                    q.push({x + 1, y});
                }
                if(x - 1 >= 0 && heights[x - 1][y] >= h && visited[x - 1][y] == false){
                    visited[x - 1][y] = true;
                    q.push({x - 1, y});
                }
                if(y + 1 < heights[0].size() && heights[x][y + 1] >= h && visited[x][y + 1] == false){
                    visited[x][y + 1] = true;
                    q.push({x, y + 1});
                }
                if(y - 1 >= 0 && heights[x][y - 1] >= h && visited[x][y - 1] == false){
                    visited[x][y - 1] = true;
                    q.push({x, y - 1});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacVisited(heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> atlVisited(heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<int>> ans;
        int r = heights.size();
        int c = heights[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if( i == 0 || (i != 0 && j == 0)) pacVisited[i][j] = true;
                if( i == r - 1 || (i != (r - 1) && j == (c - 1))) atlVisited[i][j] = true;
            }
        }
        multiBfs(heights, pacVisited);
        multiBfs(heights, atlVisited);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(pacVisited[i][j] && atlVisited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
