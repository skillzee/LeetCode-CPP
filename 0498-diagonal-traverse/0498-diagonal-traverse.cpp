class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> help(n + m - 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                help[i + j].push_back(matrix[i][j]);
            }
        }

        vector<int> ans;
        bool flag = false;

        for (int i = 0; i < help.size(); i++) {
            if (flag) {

                for (int j = 0; j < help[i].size(); j++) {
                    ans.push_back(help[i][j]);
                }
            } else {

                for (int j = help[i].size() - 1; j >= 0; j--) {
                    ans.push_back(help[i][j]);
                }
            }
            flag = !flag;
        }
        return ans;
    }
};