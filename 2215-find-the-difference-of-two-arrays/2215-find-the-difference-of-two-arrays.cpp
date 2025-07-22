class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<vector<int>> ans;
        vector<int> temp1;
        vector<int> temp2;
        for(auto it: st1){
            if(st2.find(it) == st2.end()){
                temp1.push_back(it);
            }
        }
        for(auto it: st2){
            if(st1.find(it) == st1.end()){
                temp2.push_back(it);
            }
        }

        ans.push_back(temp1);
        ans.push_back(temp2);


        return ans;
    }
};