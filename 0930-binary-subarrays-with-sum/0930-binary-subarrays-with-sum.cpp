class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int curr = 0;
        int ans = 0;
        mp[0] = 1;
        for(int i =0; i<n; i++){
            curr+=nums[i];
            int toFind = curr - goal;
            if(mp.find(toFind) != mp.end()){
                ans+=mp[toFind];
            }

            mp[curr]++;
        }

        return ans;
    }
};