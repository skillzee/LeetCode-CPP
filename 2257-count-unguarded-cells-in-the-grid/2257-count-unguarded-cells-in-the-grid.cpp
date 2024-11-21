class Solution {
public:

    void markGuarded(int row, int col, vector<vector<int>> &grid){
        // Up
        for(int i = row-1; i>=0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }
            grid[i][col] = 1; //Guarded marked
        }

        // Down
        for(int i = row+1; i<grid.size(); i++){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }
            grid[i][col] = 1; //Guarded marked
        }
        // Left
        for(int j = col-1; j>=0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1; //Guarded marked
        }
        for(int j = col+1; j<grid[0].size(); j++){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1; //Guarded marked
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(vector<int>& vec: guards){
            int i = vec[0];
            int j = vec[1];

            grid[i][j] = 2; //Guard
        }

        for(vector<int>& wall: walls){
            int i = wall[0];
            int j = wall[1];

            grid[i][j] = 3; // Wall
        }

        for(vector<int>& guard : guards){
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid); // Check the guarded directions
        }

        int count = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return count;

    }
};