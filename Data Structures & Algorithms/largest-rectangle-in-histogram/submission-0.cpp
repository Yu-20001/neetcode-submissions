class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> bound;
        int max_area = 0;
        int r,l,w,h,area;
        for(int i = 0; i < heights.size(); i++){            
            if(bound.empty() || heights[bound.back()] < heights[i]){
                bound.push_back(i);
            }
            else{
                while(!bound.empty() && heights[i] < heights[bound.back()]){
                    r = i - 1;
                    h = heights[bound.back()];
                    bound.pop_back();
                    if(bound.empty()){
                        l = 0;
                    }
                    else{
                        l = bound.back() + 1;
                    }
                    w = r - l + 1;
                    area = w * h;
                    if(area > max_area) max_area = area;
                }
                bound.push_back(i);
            }
           
        }
        while(!bound.empty()){
            r = heights.size() - 1;
            h = heights[bound.back()];
            bound.pop_back();
            if(bound.empty()){
                l = 0;
            }
            else{
                l = bound.back() + 1;
            }
            w = r - l + 1;
            area = w * h;
            if(area > max_area) max_area = area;
        }
        return max_area;
    }
};

