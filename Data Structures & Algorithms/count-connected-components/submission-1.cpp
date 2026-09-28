class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[node]) return;
        visited[node] = true;
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfs(neighbor, adj, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
