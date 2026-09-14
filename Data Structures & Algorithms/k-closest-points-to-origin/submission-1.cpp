class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = pow(x, 2) + pow(y, 2);
            pq.push({dist, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};
