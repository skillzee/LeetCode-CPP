class Solution {
public:
    int solve(int ind, vector<int>& nums, int target, unordered_map<string, int>& memo) {
        // Base case
        if (ind == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        // Create a unique key for the current state (ind, target)
        string key = to_string(ind) + "," + to_string(target);

        // If this state has been solved before, return the cached result
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Recursively explore adding and subtracting the current number
        int plus = solve(ind + 1, nums, target - nums[ind], memo);
        int minus = solve(ind + 1, nums, target + nums[ind], memo);

        // Cache the result before returning
        return memo[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(0, nums, target, memo);
    }
};
