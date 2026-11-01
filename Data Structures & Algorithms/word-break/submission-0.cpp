class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(string word : wordDict){
                if(i >= word.size()){
                    int j = i - word.size();
                    string str = s.substr(j, word.size());
                    if(dp[j] && str == word){
                        dp[i] = true;
                        break;
                    }
                }
                else continue;
            }
        }
        return dp[s.size()];
    }
};
