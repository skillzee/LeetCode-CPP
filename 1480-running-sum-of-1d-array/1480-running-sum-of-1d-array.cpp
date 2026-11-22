class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i<n; i++){
            curr+=nums[i];
            ans.push_back(curr);
        }

        return ans;
    }
};