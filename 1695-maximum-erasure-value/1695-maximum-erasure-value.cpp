class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();


        int l = 0;
        int r = 0;
        int sum = INT_MIN;
        set<int> st;
        int tempSum = 0;
        while(r<n){
            tempSum+=nums[r];
            while(st.find(nums[r])!=st.end()){
                tempSum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            sum=max(sum, tempSum);

            st.insert(nums[r]);
            r++;
        }


        return sum;
    }
};