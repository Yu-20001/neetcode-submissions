#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;
        std::vector<std::vector<string>> ans;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(strs[i]);
        }
        for(const auto&[key, value] : map){
            ans.push_back(value);
        }
        return ans;
    }
};
