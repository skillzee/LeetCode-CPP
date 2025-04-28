class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        int ans = 0;
        int maxOccur = INT_MIN;
        for(auto it: mp){
            maxOccur = max(it.second, maxOccur);
            if(it.second>=maxOccur){
                ans = it.first;
            }
        }
        return ans;
    }
};