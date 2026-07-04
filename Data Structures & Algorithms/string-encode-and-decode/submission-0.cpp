class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for(string str : strs){
            int len = str.size();
            string tmp = to_string(len) + "#" + str;
            encoded_str += tmp;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            string num_str = "";
            while(s[i] != '#'){
                num_str += s[i];
                i++;
            }
            i++;
            int num = stoi(num_str);
            string tmp = "";
            for(int j = 0; j < num; j++){
                tmp += s[j + i];
            }
            i = i + num;
            ans.push_back(tmp);
        }
        return ans;
    }
};
