class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int i, vector<int>& curr, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        dfs(i + 1, curr, nums);

        curr.push_back(nums[i]);
        dfs(i + 1, curr, nums);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(0, curr, nums);
        return ans;
    }
};
