#include<unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        std::unordered_map<int, int> map;
        for(int i = 0; i < size; i++){
            auto it = map.find(nums[i]);
            if(it != map.end()){
                return true;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        return false;
    }
};