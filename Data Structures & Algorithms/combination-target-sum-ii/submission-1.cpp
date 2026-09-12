class Solution {
private:
    vector<vector<int>> ans;
    void add(int i, int remain, vector<int>& curr, vector<int>& candidates){
        if(remain == 0){
            ans.push_back(curr);
            return;
        }
        if(remain < 0) return;
        if(i == candidates.size()) return;
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1]) continue;
            curr.push_back(candidates[j]);
            add(j+1, remain - candidates[j], curr, candidates);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        add(0, target, curr, candidates);
        return ans;
    }
};
