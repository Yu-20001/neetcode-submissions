class Solution {
private:
    vector<vector<int>> ans;
    void sub(int i, vector<int>& curr, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        sub(i + 1, curr, nums);
        curr.pop_back();
        sub(i + 1, curr, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> curr;
       sub(0, curr, nums);
       return ans; 
    }
};
