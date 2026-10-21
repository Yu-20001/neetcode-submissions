class Solution {
private:
    int dp(vector<int>& arr, int l, int r){
        vector<int> part;
        for(int i = l; i < r + 1; i++){
            part.push_back(arr[i]);
        }
        if(part.size() == 1) return part[0];
        if(part.size() == 2) return max(part[0], part[1]);
        
        vector<int> ans(part.size());
        ans[0] = part[0];
        ans[1] = max(ans[0], part[1]);
        for(int i = 2; i < part.size(); i++){
            ans[i] = max(ans[i - 2] + part[i], ans[i - 1]);
        }

        return ans[part.size() - 1];

    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(dp(nums, 0, nums.size() - 2), dp(nums, 1, nums.size() - 1));
    }
};
