class Solution {
public:

    int solve(int idx, vector<int>& cost, vector<int> &dp){
        if(idx ==0) return cost[0];
        if(idx ==1) return cost[1];
        if(dp[idx]!=-1){
            return dp[idx];
        }

        int take = cost[idx] + solve(idx-1, cost, dp);
        int notTake = cost[idx]+ solve(idx-2, cost,dp);

        return dp[idx] = min(take, notTake);
        
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};