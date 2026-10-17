class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++){
            if(st.empty() || temperatures[i] <= st.top().first){
                st.push({temperatures[i], i});
            }
            else{
                while(!st.empty() && temperatures[i] > st.top().first){
                    // int id = hMap[st.top()];
                    int id = st.top().second;
                    ans[id] = i - id;
                    st.pop();
                }
                st.push({temperatures[i], i});
            }
        }
        while(!st.empty()){
            // int id = hMap[st.top()];
            int id = st.top().second;
            ans[id] = 0;
            st.pop();
        }
        return ans;
    }
};
