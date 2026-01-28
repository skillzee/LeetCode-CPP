class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp; // ye nums2 mein kaam krega what we are doing is we are kind of precomputing the next greater element

        stack<int> st;
        for(int i = n-1;i>=0; i--){
            int num = nums2[i];
            
           
            while(!st.empty() and st.top()<num){
                st.pop();
            }
            if(st.empty()){
                mp[num] = -1;
            }else{
                mp[num] = st.top();
            }

            st.push(num);

        }

        vector<int> ans;

        for(auto it: nums1){
            ans.push_back(mp[it]);
        }


        return ans;
    }
};