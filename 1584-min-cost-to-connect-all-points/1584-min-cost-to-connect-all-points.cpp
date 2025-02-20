class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int,int>>> graph;
        for(int i = 0; i<n; i++){
            int u = i;
            for(int j = u+1; j<n; j++){
                int v = j;
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                graph[u].push_back({v, wt});
                graph[v].push_back({u, wt});
                
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});
        vector<bool> inMST(n, false);
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;

            int node = it.second;
            if(inMST[node] == true) continue;
            inMST[node] = true;
            sum+=wt;
            for(auto &neighbour: graph[node]){
                int adjNode = neighbour.first;
                int adjWt = neighbour.second;
                if(!inMST[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;

    }
};