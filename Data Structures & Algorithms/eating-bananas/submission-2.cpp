class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(int pile : piles){
            max = pile > max ? pile : max;
        }
        int l = 1;
        int r = max;
        while(l < r){
            int mid = (l + r) / 2;
            int time = 0;
            for(int pile : piles){
                time += (pile + (mid - 1)) / mid;
            }
            if(time > h){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};
