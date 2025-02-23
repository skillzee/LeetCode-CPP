class Solution {
public:
    void dfs(int startNode, int target, vector<int>& path, vector<vector<int>>& graph, vector<vector<int>>& ans) {
        path.push_back(startNode);
        if (startNode == target) {
            ans.push_back(path);
        } else {
            for (auto it : graph[startNode]) {

                dfs(it, target, path, graph, ans);
            }
        }
    path.pop_back();
    }


vector<vector<int>>
allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;

    int n = graph.size();
    vector<int> path;
    dfs(0, n - 1, path, graph, ans);

    return ans;
}
}
;