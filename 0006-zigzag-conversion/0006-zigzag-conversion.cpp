class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int col = 0;
        bool toggle = true;
        int i = 0;
        while (i < n) {
            if (toggle) {
                i += numRows;
                col++;
                toggle = false;
            } else {
                int idx = i;
                for (int j = i; j < min(idx + numRows - 2, n); j++) {
                    col++;
                    i++;
                }
                toggle = true;
            }
        }
        vector<vector<char>> ans(numRows, vector<char>(col, ' '));
        string fans = "";
        int idx = 0;
        col = 0;
        toggle = true;
        while (idx < n) {
            if (toggle) {
                for (int row = 0; row < numRows && idx < n; row++) {
                    ans[row][col] = (char)(s[idx]);
                    idx++;
                }
                toggle = false;
                col++;
            } else {
                for (int row = numRows - 2; (row > 0 && idx < n); row--) {
                    ans[row][col] = (char)(s[idx]);
                    col++;
                    idx++;
                }
                toggle = true;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                if (ans[i][j] != ' ')
                    fans += ans[i][j];
            }
        }
        return fans;
    }
};