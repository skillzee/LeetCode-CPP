class Solution {
public:

    void dfs(int node,vector<int> &visited, unordered_map<int, vector<int>> &adj){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
            dfs(it, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i< isConnected.size(); i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                }
            }
        }
        
        vector<int> visited(isConnected.size(), 0);
        int count = 0;
        for(int i = 0; i<isConnected.size(); i++){
            if(!visited[i]){
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};