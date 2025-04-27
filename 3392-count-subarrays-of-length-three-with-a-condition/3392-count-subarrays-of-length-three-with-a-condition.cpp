class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<=n-3; i++){
            int first = nums[i];
            int third = nums[i+2];
            int mid = nums[i+1];
            if((first+third) == mid/2.0) ans++;
            
        }
        return ans;
    }
};