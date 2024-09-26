class Solution {
public:

    int f(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == nums.size()){ 
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev];
        }
        
        int take= 0;
        if(prev == -1 || nums[prev]<nums[curr]){
            take = 1+f(nums, curr+1, curr, dp);
        }
        int notTake = f(nums, curr+1, prev,dp);

        return dp[curr][prev+1] = max(take, notTake);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(nums, 0, -1, dp);
    }
};