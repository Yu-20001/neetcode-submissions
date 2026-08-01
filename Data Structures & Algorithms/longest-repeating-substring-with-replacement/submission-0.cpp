class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        vector<int> count(26, 0);
        int max = 0;
        for(int r = 0; r < s.size(); r++){
            int i = s[r] - 'A';
            count[i]++;
            if(count[i] > max) max = count[i];
            if((r - l + 1) > (max + k)){
                count[s[l] - 'A']--;
                l++;
            }
        }
    return s.size() - l;
    }
};
