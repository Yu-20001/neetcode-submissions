class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        unordered_set<char> hset;
        int max = 0, tmp = 0;
        for(int i = 0; i < s.size(); i++){
            if(!hset.count(s[i])){
                hset.insert(s[i]);
                r = i;
                tmp = r - l + 1;
                if(tmp > max) max = tmp;
            }
            else{
                while(s[l] != s[i]){
                    hset.erase(s[l]);
                    l++;
                }
                l++;
                tmp = r - l + 1;
                if(tmp > max) max = tmp;
            }
        }
        return max;
    }
};
