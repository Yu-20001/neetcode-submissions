class Solution {
private:
    vector<vector<int>> ans;
    void add(int i, int remain, vector<int>& curr, vector<int>& nums){
        if(remain == 0){
            ans.push_back(curr);
            return;
        }
        if(remain < 0){
            return;
        }
        if(i == nums.size()) return;

        curr.push_back(nums[i]);
        add(i, remain - nums[i], curr, nums);
        curr.pop_back();

        add(i+1, remain, curr, nums);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        add(0, target, curr, nums);
        return ans;
    }
};
