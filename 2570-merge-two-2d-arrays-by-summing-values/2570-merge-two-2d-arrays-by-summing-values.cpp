class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i<nums1.size(); i++){
            int id = nums1[i][0];
            int val = nums1[i][1];
            mp[id]+=val;
        }
        for(int i = 0; i<nums2.size(); i++){
            int id = nums2[i][0];
            int val = nums2[i][1];
            mp[id]+=val;
        }

        for(auto it: mp){
            ans.push_back({it.first, it.second});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};