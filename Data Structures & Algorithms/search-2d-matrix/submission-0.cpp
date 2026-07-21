class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top_row = 0;
        int bot_row = matrix.size() - 1;
        int n = matrix[0].size();
        int mid_row;
        while(top_row <= bot_row){
            mid_row = (top_row + bot_row) / 2; 
            int row_end = matrix[mid_row][n - 1];
            int row_start = matrix[mid_row][0];
            if(row_end == target || row_start == target) return true;
            else{
                if(row_start < target && row_end > target) break;
                else if(row_start > target) bot_row = mid_row - 1;
                else{
                    top_row = mid_row + 1;
                }
            }
        }
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[mid_row][mid] == target) return true;
            else if(matrix[mid_row][mid] > target) r = mid - 1;
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};
