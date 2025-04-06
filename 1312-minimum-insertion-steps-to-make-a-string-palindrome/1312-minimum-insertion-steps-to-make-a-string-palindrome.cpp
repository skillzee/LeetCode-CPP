class Solution {
public:
    int lcs(string &s1, string &s2){
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 1; i<=n;i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s) {
        string s1 = s;
        // Ismein humne kya kiya hai ki pehle LPS nikala aur fir jo humare paas singular bache honge vhi to unka pair chahiye hoga to vo hi number of insertions honge aur vo hi number of deletions bhi honge.
        reverse(s1.begin(), s1.end());

        int LPS = lcs(s, s1);
        

        return s.length()-LPS;
    }
};