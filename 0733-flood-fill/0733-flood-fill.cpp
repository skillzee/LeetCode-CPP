class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int originalColor, vector<vector<int>>& visited, vector<vector<int>>& ans){
       
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sr>=n || sc<0 || sc>=m || visited[sr][sc] || image[sr][sc] != originalColor){
            return;
        }
        visited[sr][sc] = 1;
        ans[sr][sc] = color;
        dfs(image, sr-1, sc, color,originalColor, visited, ans);
        dfs(image, sr, sc-1, color,originalColor, visited, ans);
        dfs(image, sr, sc+1, color,originalColor, visited, ans);
        dfs(image, sr+1, sc, color,originalColor, visited, ans);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        
        int originalColor = image[sr][sc];
        // ans[sr][sc] = originalColor;
        // if(originalColor != color){
            // dfs(image, sr, sc, color, originalColor,  visited, ans);
        // }

        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans[row][col] = color;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for(int i = 0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol] != 1 and image[nrow][ncol] == originalColor){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                    // ans[nrow][ncol] = color;
                }
            }
            
            

        }


        return ans;
    }
};