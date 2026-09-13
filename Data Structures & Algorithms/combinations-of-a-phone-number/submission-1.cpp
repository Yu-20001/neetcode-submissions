class Solution {
private:
    vector<string> ans;
    vector<string> letters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void form(int i, string& digits, string& curr){
        if(i == digits.size()){
            ans.push_back(curr);
            return;
        }
        int num = digits[i] - '0';
        for(char ch : letters[num]){
            curr += ch;
            form(i + 1, digits, curr);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        string curr = "";
        form(0, digits, curr);
        return ans;
    }
};
