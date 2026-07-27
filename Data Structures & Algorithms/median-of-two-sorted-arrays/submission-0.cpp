class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n, m, k;
        const vector<int>& A = (nums1.size() < nums2.size()) ? nums1 : nums2;
        const vector<int>& B = (nums1.size() < nums2.size()) ? nums2 : nums1;
        n = A.size();
        m = B.size();

        int l = 0, r = n;
        while(l <= r){
            int i = (l + r) / 2;
            int j = (n + m + 1) / 2 - i;
            int L1 = (i == 0) ? INT_MIN : A[i-1];
            int R1 = (i == n) ? INT_MAX : A[i];
            int L2 = (j == 0) ? INT_MIN : B[j-1];
            int R2 = (j == m) ? INT_MAX : B[j];
            if(L1 <= R2 && L2 <= R1){
                if((n + m) % 2 == 1) return max(L1, L2);
                else{
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                }
            }
            else if(L1 > R2){
                r = i - 1;
            }
            else{
                l = i + 1;
            }
        }
        return -1;
    }
};
