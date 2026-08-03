class Solution {
public:
    string minWindow(string s, string t) {
        int min_len = 1001;
        int min_l, min_r;
        if(s.size() < t.size()) return "";
        vector<int> count(52, 0);
        string ans = "";
        for(char c:t){
            if(c >= 'a' && c <= 'z') count[c - 'a']++;
            else{
                count[c - 'A' + 26]++;
            }
        }
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            if(s[r] >= 'a' && s[r] <= 'z') count[s[r] - 'a']--;
            else{
                count[s[r] - 'A' + 26]--;
            }
            bool clear = true;
            for(int n:count){
                if(n > 0) clear = false;
            }
            if(clear){
                while(clear){
                    if(r - l + 1 < min_len){
                        min_len = r - l + 1;
                        min_l = l;
                        min_r = r;
                    }
                    int index = s[l] >= 'a' && s[l] <= 'z' ? s[l] - 'a' : s[l] - 'A' + 26;
                    count[index]++;
                    l++;
                    for(int n:count){
                        if(n > 0){
                            clear = false;
                            break;
                        }
                    }
                }
            }
        }
        for(int i = min_l; i <= min_r; i++){
                ans += s[i];
        }
        return ans;
    }
};
