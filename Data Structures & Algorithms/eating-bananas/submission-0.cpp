class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int n:piles){
            if(n > r) r = n;
        }
        while(l <= r){
            int mid = (l + r) / 2;
            long long sum_h = 0;
            for(int n:piles){
                sum_h += (n + mid - 1) / mid ;
            }
            if(sum_h <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
