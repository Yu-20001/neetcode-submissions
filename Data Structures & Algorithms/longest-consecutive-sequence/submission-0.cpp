class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int n : nums){
            if(!numSet.count(n-1)){
                int len = 1;
                while(numSet.count(n+1)){
                    len++;
                    n++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
