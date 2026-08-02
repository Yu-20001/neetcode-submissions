class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int s1_len = s1.size();
        vector<int> count(26,0);
        for(char c:s1){
            int index = c - 'a';
            count[index]++;
        }
        int l = 0, r = 0;
        for(int i = 0; i < s1.size(); i++){
            int index = s2[i] - 'a';
            count[index]--;
        }
        bool all_zero = true;
        for(int n:count){
            if(n != 0) all_zero = false;
        }
        if(all_zero) return true;
        for(int r = s1.size(); r < s2.size(); r++){
            all_zero = true;
            int index_r = s2[r] - 'a';
            int index_l = s2[l] - 'a';
            count[index_r]--;
            count[index_l]++;
            l++;
            for(int n:count){
                if(n != 0) all_zero = false;
            }
            if(all_zero) return true;
        }
    return false;
    }
};
