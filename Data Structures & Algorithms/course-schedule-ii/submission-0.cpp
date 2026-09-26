class Solution {
private:
    vector<int> order;
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& state){
        if(state[course] == 2) return true;
        if(state[course] == 1) return false;
        state[course] = 1;
        for(int pre : adj[course]){
            if(!dfs(pre, adj, state)) return false;
        }
        state[course] = 2;
        order.push_back(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, adj, state)) return {};
        }
        return order;
    }
};
