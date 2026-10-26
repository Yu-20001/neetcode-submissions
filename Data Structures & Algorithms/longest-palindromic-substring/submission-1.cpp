class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int bestStart = 0;
        int bestLen = 1;
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                if(len == 1){
                    dp[i][j] = true;
                }
                else if(len == 2){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                }
                if(dp[i][j]){
                    if(len > bestLen){
                        bestLen = len;
                        bestStart = i;
                    }
                }
            }
        }
        return s.substr(bestStart, bestLen);
    }
};
