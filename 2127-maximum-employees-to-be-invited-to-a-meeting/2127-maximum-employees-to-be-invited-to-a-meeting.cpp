class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>&adj, vector<bool> &visited){
        queue<pair<int, int>> que; //{node, pathlength};
        que.push({start, 0});
        int maxDist = 0;

        while(!que.empty()){
            auto[currNode, dist] = que.front();
            que.pop();

            for(auto nbr: adj[currNode]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    que.push({nbr, dist+1});
                    maxDist = max(maxDist, dist+1);
                }
            }
        }
        return maxDist;
    }

    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++){
            int u = i;
            int v = fav[i];
            // u-->v
            adj[v].push_back(u); //reverse graph so that we can find length after traversal
        }

        int longestCycleEmplCount = 0;//cycle length greater than 2
        int happyCoupleEmplCount = 0; //cycle of length 2 waalon ka kitna answer aayega


        vector<bool> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                //{node, abtak ka node count}
                unordered_map<int, int> mp;

                int currNode = i;
                int currNodeCount = 0;

                while(!vis[currNode]){ //jab tak cycle nhi mila
                    vis[currNode] = true;
                    mp[currNode] = currNodeCount;

                    int nextNode = fav[currNode]; //fav of currNode
                    currNodeCount+=1;

                    if(mp.count(nextNode)){ //already visited hai aur cycle detect ho gaya hai
                        int cycleLength = currNodeCount-mp[nextNode];
                        longestCycleEmplCount = max(cycleLength, longestCycleEmplCount);

                        if(cycleLength == 2){ // HappyCoupleCase
                            //currNode <--> nextNode
                            vector<bool> visitedNodes(n, 0);
                            visitedNodes[currNode] = 1;
                            visitedNodes[nextNode] = 1;
                            happyCoupleEmplCount+=2+BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(longestCycleEmplCount, happyCoupleEmplCount);
    }
};