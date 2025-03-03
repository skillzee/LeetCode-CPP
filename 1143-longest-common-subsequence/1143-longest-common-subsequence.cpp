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

    int solveTabulation(string &text1, string &text2){
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];


    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length()-1;
        int m = text2.length()-1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(text1, text2, n, m, dp);
        return solveTabulation(text1, text2);
    }
};