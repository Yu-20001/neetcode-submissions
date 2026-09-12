class Solution {
private:
    vector<string> ans;

    void gen(int n, string& str, int cnt){
        if(n == 0 && cnt == 0){
            ans.push_back(str);
            return;
        }
        if(n > 0){
            str += '(';
            cnt++;
            gen(n-1, str, cnt);
            str.pop_back();
            cnt--;
        }
        if(cnt > 0){
            str += ')';
            cnt--;
            gen(n, str, cnt);
            str.pop_back();
            cnt++;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        int cnt = 0;
        gen(n, str, 0);
        return ans;
    }
};
