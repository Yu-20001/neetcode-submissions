class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxEnd(nums.size(), 0);
        vector<int> minEnd(nums.size(), 0);
        maxEnd[0] = nums[0];
        minEnd[0] = nums[0];
        if(nums.size() == 1) return maxEnd[0];
        for(int i = 1; i < nums.size(); i++){
            maxEnd[i] = max({maxEnd[i - 1] * nums[i], minEnd[i - 1] * nums[i], nums[i]});
            minEnd[i] = min({maxEnd[i - 1] * nums[i], minEnd[i - 1] * nums[i], nums[i]});
        }
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, maxEnd[i]);
        }
        return ans;
    }
};
