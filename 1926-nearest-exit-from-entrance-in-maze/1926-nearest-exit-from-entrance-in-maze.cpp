class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        int n = maze.size();
        int m = maze[0].size();
        // int totalSteps = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            vis[row][col] = 1;
            int currSteps = it.second;
            if( (currSteps>0) and (row==0 || row == n-1 || col == 0 || col == m-1)){
                return currSteps;
            }
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for(int i = 0; i<4; i++){
                int newr = row+dr[i];
                int newc = col+dc[i];
                if(newr>=0 and newc>=0 and newr<n and newc<m and maze[newr][newc]=='.' and vis[newr][newc]!=1){
                    q.push({{newr, newc}, currSteps+1});
                }
            }

        }
        return -1;
    }
};