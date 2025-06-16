class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            int ele = nums[i];
            for(int j = 0; j<n ;j++){
                int ele2 = nums[j];
                if(i>j) continue;
                if(nums[i]>=nums[j]) continue;
                ans = max(ele2-ele, ans);
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};