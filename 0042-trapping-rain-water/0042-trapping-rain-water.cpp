class Solution {
public:
    void rightMax(vector<int>& arr, vector<int>& height) {
        int n = height.size();
        arr[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            arr[i] = max(arr[i + 1], height[i]);
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int maxL = height[0];
        int res = 0;
        vector<int> arr(n);
        rightMax(arr, height);

        for(int i = 1; i < n; i++) {
            int maxR = arr[i];    
            if(height[i] > maxL) {
                maxL = height[i];
            } else {
                res += min(maxL, maxR) - height[i];
            }
        }
        return res;
    }
};
