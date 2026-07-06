class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int n : numSet){
            if(!numSet.count(n-1)){
                int len = 1;
                int curr = n;
                while(numSet.count(curr+1)){
                    len++;
                    curr++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
