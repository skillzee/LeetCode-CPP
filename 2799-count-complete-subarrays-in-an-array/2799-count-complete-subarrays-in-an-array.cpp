class Solution {
public:

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int originalDistinct = st.size();
        
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            set<int> st1;
            for(int j = i; j<n; j++){
                st1.insert(nums[j]);
                if(st1.size() == originalDistinct){
                    ans++;
                }
                
            }
        }

        return ans;


    }
};