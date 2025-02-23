class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i<n; i++){
            vector<int> visited(n, 0);
            visited[i] = 1;
            queue<pair<int, int>> q;
            q.push({i, 0});
            int total = 0;
            while(!q.empty()){
                int node = q.front().first;
                int level = q.front().second;
                total+=level;
                q.pop();

                for(auto it: graph[node]){
                    if(!visited[it]){
                        q.push({it, level+1});
                        visited[it] = 1;
                    }
                }
            }
            ans[i] = total;
        }

        return ans;

    }
};