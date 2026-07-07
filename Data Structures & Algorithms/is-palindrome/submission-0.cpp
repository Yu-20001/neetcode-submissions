class Solution {
public:
    bool isPalindrome(string s) {
        string clean_s = "";
        for(char c:s){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                if(c >= 'A' && c <= 'Z'){
                    int diff = int('a') - int('A');
                    char tmp = char(int(c) + diff);
                    clean_s += tmp;
                }
                else{
                    clean_s += c;
                }
            }
        }
        for(int i = 0; i < clean_s.size()/2; i++){
            if(clean_s[i] != clean_s[clean_s.size()-1-i]){
                return false;
            }
        }
    return true;
    }
};
