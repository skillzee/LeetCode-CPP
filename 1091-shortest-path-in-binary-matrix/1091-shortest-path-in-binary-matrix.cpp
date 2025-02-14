class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> distance(n*m, INT_MAX);
        pair<int, int> src = {0, 0};
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({1, src});
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
            if(row == n-1 && col == m-1) return dist;
            for(int i = 0; i<8; i++){
                int newRow = row+dr[i];
                int newCol = col+dc[i];
                if(newCol>=m || newRow>=n || newRow<0 || newCol<0 || grid[newRow][newCol] == 1){
                    continue;
                }else{
                    if(dist+1<distance[newRow * m + newCol]){
                pq.push({dist+1, {newRow, newCol}});
                distance[newRow * m + newCol] = dist + 1;
                }
                }
            }

        }

        if(distance[(n-1) * m + (m-1)] == INT_MAX) return -1;

        return distance[(n-1) * m + (m-1)] ;
        

    }
};