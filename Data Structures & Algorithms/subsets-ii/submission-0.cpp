class Solution {
private:
    vector<vector<int>> ans;
    void sub(int i, vector<int>& curr, vector<int>& nums){
        ans.push_back(curr);

        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            sub(j+1, curr, nums);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        sub(0, curr, nums);
        return ans;
    }
};
