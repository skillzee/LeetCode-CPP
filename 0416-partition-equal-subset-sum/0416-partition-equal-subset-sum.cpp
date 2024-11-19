class Solution {
public:

    bool f1(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(target == 0){
            return true;
        }

        if(ind == 0){
            return arr[0] == target;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        bool notTaken = f1(ind-1, target, arr, dp);

        bool taken = false;
        if(arr[ind] <= target){
            taken = f1(ind-1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = notTaken || taken;

    }

    bool f(int n, int k, vector<int> &arr){
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return f1(n-1, k, arr, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            sum+=nums[i];
        }
        if(sum % 2) return false;
        int target = sum/2;

        return f(n, target, nums);

        
    }
};