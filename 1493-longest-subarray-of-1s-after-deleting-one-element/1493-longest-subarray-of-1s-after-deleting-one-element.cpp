class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int countZero = 0;
        int maxLen = INT_MIN;

        while(r<n){
            if(nums[r] == 0){
                countZero++;
            }

            while(countZero>1){
                if(nums[l] == 0){
                    countZero--;
                }
                l++;

            }

            if(countZero<=1){
                int len = r-l;
                maxLen = max(len, maxLen);
            }

            r++;
        }

        return maxLen;

        
    }
};