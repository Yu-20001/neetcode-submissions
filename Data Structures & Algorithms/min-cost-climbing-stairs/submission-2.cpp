class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> step(cost.size(), 0);
        step[0] = cost[0];
        step[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            step[i] = min(step[i - 1], step[i - 2]) + cost[i];
        }
        return min(step[cost.size() - 1],step[cost.size() - 2]);
    }
};
