class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;
        while(left < right){
            int curr_left_h = heights[left];
            int curr_right_h = heights[right];
            int area = min(curr_left_h, curr_right_h) * (right - left);
            max_area = max(area, max_area);
            if(curr_left_h <= curr_right_h){
                while(left < right && heights[left] <= curr_left_h){
                    left++;
                }
            }
            else{
                while(left < right && heights[right] <= curr_right_h){
                    right--;
                }
            }
        }
        return max_area;
    }
};
