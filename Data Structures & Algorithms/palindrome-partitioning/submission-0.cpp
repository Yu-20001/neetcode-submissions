class Solution {
private:
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]) return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
    void parti(int start, string& s, vector<string>& splits){
        if(start == s.size()){
            ans.push_back(splits);
            return;
        }
        for(int end = start; end < s.size(); end++){
            string candidate = s.substr(start, end - start + 1);
            if(isPalindrome(candidate)){
                splits.push_back(candidate);
                parti(end + 1, s, splits);
                splits.pop_back();
            }
            else continue;
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> splits;
        parti(0, s, splits);
        return ans;
    }
};
