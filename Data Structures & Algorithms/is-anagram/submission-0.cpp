class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> hash;
        if(s.size()!=t.size()) return false;
        for(char c:s){
            if(hash.find(c) != hash.end()) hash[c] = hash[c] + 1;
            else{
                hash[c] = 1;
            }
        }
        for(char c:t){
            if(hash.find(c)!=hash.end()) {
                if(hash[c]==0) return false;
                hash[c] = hash[c] - 1;
            }
            else return false;
        }
        return true;
    }
};
