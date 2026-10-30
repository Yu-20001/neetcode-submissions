class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int c : coins){
                if(c <= i){
                    if(dp[i - c] == amount + 1) continue;
                    else{
                        dp[i] = min(dp[i], dp[i - c] + 1);
                    }
                }
            }
        }
        for(int i = 1; i <= amount; i++){
            if(dp[i] == amount + 1){
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
};
