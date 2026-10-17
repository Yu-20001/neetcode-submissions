class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hSet;
        vector<int> heads;
        int cnt = 0;
        int max = 0;
        for(int num : nums){
            hSet.insert(num);
        }
        for(int num : hSet){
            if(!hSet.count(num-1)) heads.push_back(num);
        }
        for(int head : heads){
            cnt = 0;
            while(hSet.count(head)){
                cnt++;
                head++;
            }
            max = cnt > max ? cnt : max;
        }
        return max;
    }
};
