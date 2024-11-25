class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i  = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            for(int i = 0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol] == 1 and visited[nrow][ncol] != 1){
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 1;
                }   
            }


        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 and visited[i][j] != 1){
                    return -1;
                }
            }
        }
        return time;

    }
};