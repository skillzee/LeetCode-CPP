class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> img1Ones;
        vector<pair<int, int>> img2Ones;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(img1[i][j] == 1){
                    img1Ones.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    img2Ones.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, int> freq;

        for(int i = 0; i<img1Ones.size(); i++){
            for(int j = 0; j<img2Ones.size(); j++){
                int row1 = img1Ones[i].first;
                int col1 = img1Ones[i].second;
                int row2 = img2Ones[j].first;
                int col2 = img2Ones[j].second;

                pair<int, int> diff = {row1- row2, col1-col2};
                // if(freq.find(diff) != freq.end()){
                //     freq[diff] +=1;
                // }else{
                //     freq[diff] = 1;
                // }

                freq[diff]++;
            }
        }


        int ans = 0;
        for(auto it: freq){
            if(it.second > ans){
                ans = it.second;
            }
        }

        return ans;

    }
};