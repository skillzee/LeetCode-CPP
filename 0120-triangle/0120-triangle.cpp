class Solution {
public:
    int f(vector<vector<int>> &triangle, int rows, int cols, vector<vector<int>> &dp){
        int size = triangle.size()-1;
        if(rows == size || cols == triangle[size].size()){
            return triangle[rows][cols];
        }

        if(dp[rows][cols]!=-1){
            return dp[rows][cols];
        }
        int down = triangle[rows][cols] + f(triangle, rows+1, cols,dp);
        int diagonal = triangle[rows][cols] + f(triangle, rows+1, cols+1, dp);

        return dp[rows][cols] = min(down, diagonal);
        
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return f(triangle, 0, 0, dp);
    }
};