class Solution {
public:
    vector<int> parent; 
    vector<int> rank;
    

    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        }

        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i<26; i++){
            parent[i] = i;
        }
        
        // Union of eqaul chars
        for(string &s: equations){
            if(s[1] == '='){
                unionByRank(s[0]-'0', s[3]-'0');
            }
        }

        for(string &s: equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int parent_first = find(first-'0');
                int parent_second = find(second-'0');

                if(parent_first == parent_second){
                    return false;
                }

            }
        }

        return true;

    }
};