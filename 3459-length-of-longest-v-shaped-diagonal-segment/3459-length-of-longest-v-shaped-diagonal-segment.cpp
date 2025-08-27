class Solution {
public:
    vector<vector<int>> directions = {{1,1}, {1,-1},{-1, -1}, {-1, 1}};

    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int i_ = i+directions[d][0];
        int j_ = j+directions[d][1];

        if(i_<0 || i_>=n || j_<0 || j_>=m || grid[i_][j_] != val){
            return 0;
        }

        int res = 0;

        int keepMoving = 1 + solve(i_, j_, d, canTurn, val == 2 ? 0 : 2, grid);
        res = max(res, keepMoving);

        if(canTurn){
            int turnAndMove = max(keepMoving, 1+solve(i_, j_, (d+1)%4, false, val==2?0:2, grid));
            res = max(res, turnAndMove);
        }

        return res;

    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d<=3; d++){ // Ye hai directions ke liye
                        result = max(result, 1+solve(i,j,d, true, 2, grid));
                    }
                }
            }
        }

        return result;
    }
};