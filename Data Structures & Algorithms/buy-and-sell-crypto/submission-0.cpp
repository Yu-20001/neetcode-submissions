class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MAX;
        int max_p = 0;
        for(int i = 0; i < prices.size(); i++){
            if(l > prices[i]) l = prices[i];
            if(prices[i] - l > max_p) max_p = prices[i] - l; 
        }
        return max_p;
    }
};
