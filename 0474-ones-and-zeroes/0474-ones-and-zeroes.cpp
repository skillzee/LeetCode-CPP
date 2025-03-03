class Solution {
public:

    int zeroCount(const string& s) {
        return count(s.begin(), s.end(), '0');
    }

    int oneCount(const string& s) {
        return count(s.begin(), s.end(), '1');
    }

    int solve(vector<string>& strs, int m, int n, int idx, vector<vector<vector<int>>> &dp){
        int no = strs.size();
        if(idx >= no){
            return 0;
        }
        if(dp[m][n][idx] != -1) return dp[m][n][idx];

        int countZeroes = zeroCount(strs[idx]);
        int countOnes = oneCount(strs[idx]);

        int take = 0;
        int notTake = 0;
        if(m>=countZeroes and n>=countOnes){
            take = 1 + solve(strs, m-countZeroes, n-countOnes, idx+1, dp);
            notTake = solve(strs, m,n, idx+1, dp);
        }else{
            notTake = solve(strs, m, n, idx+1, dp);
        }

        return dp[m][n][idx] = max(take, notTake);
        
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int no = strs.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(no+1, -1)));
        
        return solve(strs, m, n, 0, dp);
    }
};