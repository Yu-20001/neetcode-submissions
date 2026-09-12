class Solution {
private:
    vector<vector<int>> ans;
    void per(vector<bool>& used, vector<int>& curr, vector<int>& nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            per(used, curr, nums);
            used[i] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        per(used, curr, nums);
        return ans;
    }
};
