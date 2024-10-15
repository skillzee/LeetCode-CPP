class Solution {
public:
    int minInsertions(string s) {
        // What I will try to do is I will find the longest palindromic subsequence and then minus it from the actual length which should give me the minimum insertions
         string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == s1[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1]; 
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int LPS = dp[n][n];

        return s.length() - LPS;
        


    }
};