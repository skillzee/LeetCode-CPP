class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int eleI = nums[i];
            for(int j = 0; j<n; j++){
                if(j == i) continue;
                int eleJ = nums[j];
                for(int k = 0; k<n; k++){
                    if(k == j || k == i) continue;
                    int eleK = nums[k];
                    if(eleJ + eleK + eleI == 0){
                        vector<int> triplets = {eleI, eleJ, eleK};
                        sort(triplets.begin(), triplets.end());
                        ans.insert(triplets);
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};