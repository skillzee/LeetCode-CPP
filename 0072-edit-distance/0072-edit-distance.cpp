class Solution {
public:
    int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
        if (i >= str1.length()) return str2.length() - j; 
        if (j >= str2.length()) return str1.length() - i; 
        
        if (str1[i] == str2[j]) {
            return solve(str1, str2, i + 1, j + 1, dp); 
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }

        int op1 = 1 + solve(str1, str2, i + 1, j, dp);   
        int op2 = 1 + solve(str1, str2, i, j + 1, dp);  
        int op3 = 1 + solve(str1, str2, i + 1, j + 1, dp);  
        
        return dp[i][j] = min({op1, op2, op3});
    }

    int minDistance(string str1, string str2) {
        vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
        return solve(str1, str2, 0, 0, dp);
    }
};
