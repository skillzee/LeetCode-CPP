class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int currSum = 0;
        int ans = 0;
        while (r < n) {
            currSum += nums[r];
            while (currSum > goal and l < n) {
                currSum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return helper(nums, goal) - helper(nums, goal - 1);
    }
};