class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        vector<int> result(temperatures.size());
        int prev_day;
        for(int i = 0; i < temperatures.size(); i++){
            if(st.empty() || temperatures[st.back()] >= temperatures[i]){
                st.push_back(i);
            }
            else{
                while(!st.empty() && temperatures[st.back()] < temperatures[i]){
                    prev_day = st.back();
                    result[prev_day] = i - prev_day;
                    st.pop_back();
                }
                st.push_back(i);
            }
        }
        return result;
    }
};

//[0,2,3,4]
//[0,1,0,0,0,0,0,0,0,0]