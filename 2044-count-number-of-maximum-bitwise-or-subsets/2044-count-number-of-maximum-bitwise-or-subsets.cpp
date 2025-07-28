class Solution {
public:

    int countSubsets(int idx, int currOr, vector<int> &nums, int maxOr, vector<vector<int>> &dp){

        if(idx>=nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }
        if(dp[idx][currOr]!=-1){
            return dp[idx][currOr];
        }

        // take
        int take = countSubsets(idx+1, currOr|nums[idx], nums, maxOr, dp);

        // not take
        int notTake = countSubsets(idx+1, currOr, nums, maxOr, dp);

        return dp[idx][currOr] = take+notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num: nums){
            maxOr |= num;
        }
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(maxOr+1, -1));

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr, dp);
    }
};