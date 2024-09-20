class Solution {
public:
    int rightMax(int ind, vector<int>& height) {
        int right = 0;
        for(int i = ind; i < height.size(); i++) {
            right = max(right, height[i]);
        }
        return right;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int maxL = height[0];
        int res = 0;

        for(int i = 1; i < n; i++) {
            int maxR = rightMax(i, height);
            if(height[i] > maxL) {
                maxL = height[i];
            } else {
                res += min(maxL, maxR) - height[i];
            }
        }
        return res;
    }
};
