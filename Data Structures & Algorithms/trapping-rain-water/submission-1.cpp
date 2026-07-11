class Solution {
public:
    int trap(vector<int>& height) {
        int max_l = 0;
        int max_r = 0;
        int left = 0, right = height.size() - 1;
        int sum = 0;
        int tmp;
        while(left < right){
            if(height[left] <= height[right]){
                max_l = max(max_l, height[left]);
                tmp = max(max_l - height[left], 0);
                sum += tmp;
                left++;          
                
            }
            else{
                max_r = max(max_r, height[right]);
                tmp = max(max_r - height[right], 0);
                sum += tmp;
                right--;
            }
        }
        return sum;
    }
};
