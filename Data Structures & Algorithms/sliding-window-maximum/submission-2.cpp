class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int r = 0; r < nums.size(); r++){
            if(dq.empty()){
                dq.push_back(r);
            }
            else{
                if(dq.front() < r - k + 1) dq.pop_front();
                while(!dq.empty() && nums[dq.back()] <= nums[r]){
                    dq.pop_back();
                }
                dq.push_back(r);
            }
            if(r >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
