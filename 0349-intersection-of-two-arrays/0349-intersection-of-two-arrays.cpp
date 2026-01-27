class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        set<int> st(nums1.begin(), nums1.end());
        set<int> ansSet;
        for(auto it: nums2){
            if(st.find(it) != st.end()){
                ansSet.insert(it);
            }
        }


        for(auto it: ansSet){
            ans.push_back(it);
        }

        return ans;


    }
};