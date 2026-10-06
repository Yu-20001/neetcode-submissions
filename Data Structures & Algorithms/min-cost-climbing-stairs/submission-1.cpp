class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> step(cost.size(), 0);
        step[0] = cost[0];
        step[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int prev1 = step[i - 1] + cost[i];
            int prev2 = step[i - 2] + cost[i];
            step[i] = prev1 < prev2 ? prev1 : prev2;
        }
        return min(step[cost.size() - 1],step[cost.size() - 2]);
    }
};
