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

        curr.push_back(candidates[i]);
        add(i + 1, remain - candidates[i], curr, candidates);
        curr.pop_back();
        while(i + 1 < candidates.size() && candidates[i + 1] == candidates[i]){
            i++;
        }
        add(i + 1, remain, curr, candidates);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        add(0, target, curr, candidates);
        return ans;
    }
};
