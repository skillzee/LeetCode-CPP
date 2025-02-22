class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& rooms){
        visited[node] = 1;
        for(auto it: rooms[node]){
            if(!visited[it]){
                dfs(it, visited, rooms);
            }
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n , 0);

        // visited[0] = 1;
        dfs(0, visited, rooms);

        for(auto it: visited){
            if(it == 0){
                return false;
            }
        }

        return true;
    }
};