

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> elements(nums.begin(), nums.end());
        int longestStreak = -1;

        for (int num : nums) {
            int streak = 0;
            int current = num;
            while (elements.count(current)) {
                streak++;
                current *= current; 
            }
            longestStreak = max(longestStreak, streak);
        }
        return longestStreak == 1 ? -1 : longestStreak;
    }
};
