class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int currOdd = 0;
        int ans = 0;
        mp[0] = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 1){
                currOdd++;
            }
            if(mp.find(currOdd-k) != mp.end()){
                ans+=mp[currOdd-k];
            }
            mp[currOdd]++;
        }

        return ans;
    }
};