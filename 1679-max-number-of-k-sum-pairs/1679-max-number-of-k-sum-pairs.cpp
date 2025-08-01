class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int count = 0;

        for (int num : nums) {
            int complement = target - num;
            if (mp[complement] > 0) {
                count++;
                mp[complement]--;
            } else {
                mp[num]++;
            }
        }

        return count;
    }
};