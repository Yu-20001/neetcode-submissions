class Solution {
private:
    int bestLen = 1;
    int bestStart = 0;
    void expand(string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        int start = l + 1;
        int len = r - l - 1;
        if(len > bestLen){
            bestLen = len;
            bestStart = start;
        }
    }
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i);
            if(i + 1 < s.size()) expand(s, i, i + 1);
        }
        return s.substr(bestStart, bestLen);
    }
};
