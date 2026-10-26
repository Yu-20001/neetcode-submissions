class Solution {
private:
    int cnt = 0;
    void expand(string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
            cnt++;
        }
    }
public:
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i);
            if(i + 1 < s.size()) expand(s, i, i + 1);
        }
        return cnt;
    }
};
