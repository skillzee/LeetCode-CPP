class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &graph, int dest, int node, vector<int> &vis){
        vis[node] = 1;

        for(auto it: graph[node]){
            if(it == dest){
                return true;
            }
            if(!vis[it]){
                if(dfs(graph, dest, it, vis)) return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        if(edges.size() == 0) return true;

        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> vis(n, 0);

        return dfs(graph, destination, source, vis);
    }
};