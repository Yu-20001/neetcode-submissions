class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.size() + 1, 0);
        ways[0] = 1;
        for(int i = 1; i <= s.size(); i++){
            if(s[i - 1] != '0'){
                ways[i] += ways[i - 1];
            }
            if(i >= 2){
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if(num >= 10 && num <= 26){
                    ways[i] += ways[i - 2];
                }
            }
        }
        return ways[s.size()];
    }
};
