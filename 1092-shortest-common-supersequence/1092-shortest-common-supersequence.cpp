class Solution {
public:
    void lcs(string s1, string s2, vector<vector<int>> &dp) {
        int n = s1.length(), m = s2.length();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        lcs(str1, str2, dp);

        int i = n, j = m;
        string s = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]);
                i--; j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    s.push_back(str1[i - 1]);
                    i--;
                } else {
                    s.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0) {
            s.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            s.push_back(str2[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};
