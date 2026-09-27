class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& state){
        if(state[node] == 2) return true;
        if(state[node] == 1) return false;
        state[node] = 1;
        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;
            if(!dfs(neighbor, node, adj, state)) return false;
        }
        state[node] = 2;
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> state(n, 0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(!dfs(i, -1, adj, state)) return false;
            for(int j = 0; j < n; j++){
                if(state[j] == 0) return false;
            }
        }
        return true;
    }
};
