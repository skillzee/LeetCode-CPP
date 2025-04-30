class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int tempAns;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                tempAns++;
                ans = max(ans, tempAns);
            }if(nums[i]!=1){
                tempAns = 0;
                continue;
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};