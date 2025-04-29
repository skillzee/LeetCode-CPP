class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        long long ans = 0;
        int numOccurences = 0;
        while(r<n){
            if(nums[r] == maxi){
                numOccurences++;
            }
            while(numOccurences >= k){
                ans+=n-r;
                if(nums[l] == maxi){
                    numOccurences--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }

};