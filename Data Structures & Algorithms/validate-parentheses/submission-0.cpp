class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(char c:s){
            if(c == '('){
                stack.push_back(')');
            }
            else if(c == '['){
                stack.push_back(']');
            }
            else if(c == '{'){
                stack.push_back('}');
            }
            else{
                if(!stack.empty()){
                    if(c == stack.back()){
                        stack.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
