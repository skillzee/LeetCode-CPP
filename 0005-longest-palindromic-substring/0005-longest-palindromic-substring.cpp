class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start=-1;
        int end=-1;
        for(int len = 1; len<=n; len++){
            for(int i = 0; i<n; i++){
                int j = i+len-1;
                if(j>=n){
                    continue;
                }
                if(s[i]!=s[j]){
                    dp[i][j] = 0;
                }
                else{
                    if(i+1>=j-1){
                        // ans++;
                        dp[i][j] = 1;
                        start = i;
                        end = j;
                    }

                    else{
                        // ans+=dp[i+1][j-1];
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        if(start == -1) return "";
        return s.substr(start,end-start+1);
    }
};