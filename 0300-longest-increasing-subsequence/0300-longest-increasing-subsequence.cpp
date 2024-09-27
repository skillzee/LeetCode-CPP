class Solution {
public:

    int f(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == nums.size()){ 
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
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
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f(nums, 0, -1, dp);


        vector<int> dp(n, 1);
        int maxi = -1;
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i]){
                    dp[i] = max(dp[i], 1+dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};