class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>num_st;
        for(string str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int num1, num2;
                num2 = num_st.back();
                num_st.pop_back();
                num1 = num_st.back();
                num_st.pop_back();
                if(str == "+") num_st.push_back(num1 + num2);
                else if(str == "-") num_st.push_back(num1 - num2);
                else if(str == "*") num_st.push_back(num1 * num2);
                else num_st.push_back(num1 / num2);
            }
            else{
                num_st.push_back(stoi(str));
            }
        }
        return num_st.back();
    }
};
