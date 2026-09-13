class Solution {
private:
    vector<string> ans;
    void form(int i, string& digits, string& curr){
        if(i == digits.size()){
            ans.push_back(curr);
            return;
        }
        int num = digits[i] - '0';
        if(num < 7){
            char ch = 'a' + 3 * (num - 2);
            curr += ch;
            form(i+1, digits, curr);
            curr.pop_back();
            
            curr += (ch + 1);
            form(i+1, digits, curr);
            curr.pop_back();

            curr += (ch + 2);
            form(i+1, digits, curr);
            curr.pop_back();
        }
        else{
            if(num == 7 || num == 9){
                char ch = num == 7 ? 'p' : 'w';
                curr += ch;
                form(i+1, digits, curr);
                curr.pop_back();
                
                curr += ch + 1;
                form(i+1, digits, curr);
                curr.pop_back();

                curr += ch + 2;
                form(i+1, digits, curr);
                curr.pop_back();

                curr += ch + 3;
                form(i+1, digits, curr);
                curr.pop_back();
            }
            else{
                char ch = 't';
                curr += ch;
                form(i+1, digits, curr);
                curr.pop_back();
                
                curr += (ch + 1);
                form(i+1, digits, curr);
                curr.pop_back();

                curr += (ch + 2);
                form(i+1, digits, curr);
                curr.pop_back();
            }
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
