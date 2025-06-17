class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            if(nums[i]<=0 || nums[i]>n) continue;
            check[nums[i]] = 1;
        }
        for(int i = 1; i<=n; i++){
            if(!check[i]){
                ans = i;break;
            }
        }
        if(ans == INT_MIN) return n+1;

        return ans;

    }
};