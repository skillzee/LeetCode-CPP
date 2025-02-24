class Solution {
public:

    int dfs(unordered_map<int, vector<int>> &adj, int currNode, int parent, vector<bool> &hasApple){
        int time = 0;

        for(int &child: adj[currNode]){
            if(child == parent) continue;

            int timeFromChild = dfs(adj, child, currNode, hasApple);

            if(timeFromChild>0 || hasApple[child]){
                time+=timeFromChild+2;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0, -1, hasApple);

    }
};