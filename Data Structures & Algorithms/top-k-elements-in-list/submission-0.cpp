#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(nums[i]);
            if(it != map.end()){
                map[nums[i]]++;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        for(auto const& [val, freq] : map){
            bucket[freq].push_back(val);
        }
        vector<int> ans;
        int cnt = k;
        for(int i = nums.size(); i >= 0 && cnt > 0; i--){
            for(int val : bucket[i]) {
                if (cnt > 0) {
                    ans.push_back(val);
                    cnt--;
                }
            }
        }
        return ans;
    }
};
