class Solution {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    bool uni(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        if(rootU == rootV) return false;
        else{
            parent[rootV] = rootU;
            return true;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i <= edges.size(); i++){
            parent.push_back(i);
        }
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(uni(u, v)) continue;
            else{
                return{u, v};
            }
        }
        return {-1, -1};
    }
};
