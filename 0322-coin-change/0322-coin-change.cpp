class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                int ans = solve(coins, amount - coins[i], dp);
                if (ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        return dp[amount] = mini;
    }

    int solveUsingTabulation(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (coins[i] <= value) {
                    int ans = dp[value - coins[i]];
                    if (ans != INT_MAX) {
                        mini = min(mini, 1 + ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        // int ans = solve(coins, amount, dp);
        int ans = solveUsingTabulation(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
