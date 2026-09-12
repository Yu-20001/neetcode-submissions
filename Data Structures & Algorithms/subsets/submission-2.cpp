class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int start, vector<int>& curr, vector<int>& nums){
        if(start == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        dfs(start + 1, curr, nums);
        curr.pop_back();
        dfs(start + 1, curr, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(0, curr, nums);
        return ans;
    }
};
