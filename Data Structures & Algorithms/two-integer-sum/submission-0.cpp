class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0; i<nums.size(); ++i){
            int x;
            x = target - nums[i];
            if(hash.find(nums[i])!=hash.end()){
                return {hash[nums[i]], i};
            }
            else hash[x]=i;
        }
    }
};
