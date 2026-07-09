class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            else{
                vector<int> tmp;
                int r = 0 - nums[i];
                int pre = i + 1;
                int suf = nums.size() - 1;
                while(pre < suf){
                    int sum = nums[pre] + nums[suf];
                    if(sum < r){
                        pre++;
                    }
                    else if(sum > r){
                        suf--;
                    }
                    else{
                        tmp = {nums[i], nums[pre], nums[suf]};
                        ans.push_back(tmp);
                        while(pre < suf && nums[pre+1] == nums[pre]) pre++;
                        while(pre < suf && nums[suf-1] == nums[suf]) suf--;
                        pre++;
                        suf--;
                    }
                }
            }
        }
        return ans;
    }
};
