class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;

        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = m;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int j = half - mid;

            int l1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int r1 = (mid == m) ? INT_MAX : nums1[mid];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if(l1 <= r2 && l2 <= r1){
                if(total % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            } else if(l1 > r2){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return 0.0;
    }
};
