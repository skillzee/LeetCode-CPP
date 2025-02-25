class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 1;
        int prefixSum = 0, ans = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            } else {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }
        }
        
        return ans;
    }
};
