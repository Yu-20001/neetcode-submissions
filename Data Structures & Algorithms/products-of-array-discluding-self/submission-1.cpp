class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        vector<int> suf;
        int n = nums.size();
        pre.push_back(1);
        int tmp = 1;
        for(int i = 0; i < n; i++){
            tmp *= nums[i];
            pre.push_back(tmp);
        }
        pre.push_back(1); //{1,1,2,8,48,1}
        suf.push_back(1);
        tmp = 1;
        for(int i = n-1; i >= 0; i--){
            tmp *= nums[i];
            suf.push_back(tmp);
        }
        suf.push_back(1); //{1,6,24,48,48,1}
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(pre[i] * suf[n-1-i]); //ans[0] = pre[0] * suf[3-0]; ans[1] = pre[1]
        }
        return ans;
    }
};
