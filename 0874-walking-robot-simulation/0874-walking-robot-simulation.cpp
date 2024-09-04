class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        string direc = "+Y";
        pair<int,int> currLoc = {0, 0};
        vector<int> distances;
        set<pair<int,int>> st;

        for(int i = 0; i < obstacles.size(); i++){
            int u = obstacles[i][0];
            int v = obstacles[i][1];
            st.insert({u,v});
        }

        for(int i = 0; i < commands.size(); i++){
            int obj = commands[i];
            if(direc == "+Y" and obj == -1){
                direc = "+X";
            }
            else if(direc == "+Y" and obj == -2){
                direc = "-X";
            }
            else if(direc == "+X" and obj == -1){
                direc = "-Y";
            }
            else if(direc == "+X" and obj == -2){
                direc = "+Y";
            }
            else if(direc == "-Y" and obj == -1){
                direc = "-X";
            }
            else if(direc == "-Y" and obj == -2){
                direc = "+X";
            }
            else if(direc == "-X" and obj == -1){
                direc = "+Y";
            }
            else if(direc == "-X" and obj == -2){
                direc = "-Y";
            }
            else{
                for(int j = 1; j <= obj; j++){
                    int row = currLoc.first;
                    int col = currLoc.second;
                    if(direc == "+Y") col++;
                    if(direc == "-Y") col--;
                    if(direc == "+X") row++;
                    if(direc == "-X") row--;

                    if(st.find({row, col}) != st.end()) break; 
                    currLoc = {row, col}; 
                    int ans = (row * row) + (col * col); 
                    distances.push_back(ans);
                }
            }
        }
        
        if(distances.empty()) return 0; 
        return *max_element(distances.begin(), distances.end()); 
    }
};
