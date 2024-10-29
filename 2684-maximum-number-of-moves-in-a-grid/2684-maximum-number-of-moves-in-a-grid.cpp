class Solution {
public:
    int n;
    int m;
    vector<int> directions = {-1, 0, 1};
    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int moves = 0;
        for(int &dir : directions){
            int newRow = row+ dir;
            int newCol = col+1;

            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and grid[newRow][newCol]>grid[row][col]){
                moves = max(moves, 1+ DFS(newRow, newCol, grid, dp));
            }
        }
        return dp[row][col] = moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int result = 0;


        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int row = 0; row<n; row++){
            result = max(result, DFS(row, 0, grid, dp));
        }

        return result;
    }
};