class Solution {
public:
    int solve(string word1, string word2, int n, int m, vector<vector<int>> &dp) {
        if (n == word1.length()) {
            return word2.length() - m;  // Insert all remaining chars of word2
        }
        if (m == word2.length()) {
            return word1.length() - n;  // Delete all remaining chars of word1
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        // If characters match, no operation needed, move to next character
        if (word1[n] == word2[m]) {
            return dp[n][m] = solve(word1, word2, n+1, m+1, dp);
        }

        // Explore all possible operations: delete, insert, substitute
        int deletion = 1 + solve(word1, word2, n+1, m, dp);
        int insertion = 1 + solve(word1, word2, n, m+1, dp);
        // int substitution = 1 + solve(word1, word2, n+1, m+1, dp);

        // Return the minimum of the three operations
        return dp[n][m] = min({deletion, insertion});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
