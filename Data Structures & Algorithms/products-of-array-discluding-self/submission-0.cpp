class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        vector<int> suf;
        int tmp = 1;
        for(int i = 0; i < nums.size(); i++){
            tmp *= nums[i];
            pre.push_back(tmp);
        }
        tmp = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            tmp *= nums[i];
            suf.push_back(tmp);
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                ans.push_back(suf[nums.size() - 2]);
            }
            else if(i == nums.size() - 1){
                ans.push_back(pre[nums.size() - 2]);
            }
            else{
                ans.push_back(pre[i - 1] * suf[nums.size() - 2 - i]);
            }
        }
        return ans;
    }
};
