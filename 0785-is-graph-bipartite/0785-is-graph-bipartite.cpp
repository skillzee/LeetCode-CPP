class Solution {
public:

    bool dfs(vector<vector<int>> &graph, int node, vector<int> &color, int currColor){
        color[node] = currColor;

        for(auto it: graph[node]){
            if(color[node] == color[it]){
                return false;
            }
            if(color[it] == -1){
            if(dfs(graph, it, color, !currColor) == false){
                return false;
            }
            }
        }

        return true;

    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n ;i++){
            if(color[i] == -1){
            if(!dfs(graph, i, color, 0)){
                return false;
            }
            }
        }

        return true;
    }
};