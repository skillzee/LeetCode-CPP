class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int, int>> q; // Ye for node and color

         // 1 based indexing graph or 0 for color1 and 1 for
                        // color2 (Check kr rha hun final nhi pata);
        vector<pair<int, int>> visited(n + 1, {0, 0});
        ; // visited and color
        for (int i = 1; i <= n; i++) {
            if(!visited[i].first){
                q.push({i, 1});
                visited[i] = {1, 1};
            }
            while (!q.empty()) {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();

                for (auto it : graph[node]) {
                    if (visited[it].first and visited[it].second == color) {
                        cout << it << " ";
                        return false;
                    } else if (!visited[it].first) {
                        q.push({it, !color});
                        visited[it].first = 1;
                        visited[it].second = !color;
                    }
                }
            }
        }
        return true;
    }
};