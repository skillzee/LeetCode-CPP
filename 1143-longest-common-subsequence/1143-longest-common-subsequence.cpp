class Solution {
public:
    int solve(string text1, string text2, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1<0 || idx2<0){
            return 0;
        }

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1+solve(text1, text2, idx1-1, idx2-1, dp);
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        int op1 = solve(text1, text2, idx1-1, idx2, dp);
        int op2 = solve(text1, text2, idx1, idx2-1, dp);
        return dp[idx1][idx2] = max(op1, op2);
    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length()-1;
        int m = text2.length()-1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, n, m, dp);
    }
};