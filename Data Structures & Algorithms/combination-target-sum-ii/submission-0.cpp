class Solution {
private:
    vector<vector<int>> ans;
    void add(int start, int remain, vector<int>& curr, vector<int>& candidates){
        if(remain == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < candidates.size(); i++){     
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > remain) break;
            curr.push_back(candidates[i]);
            add(i+1, remain - candidates[i], curr, candidates);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        add(0, target, curr, candidates);
        return ans;
    }
};
