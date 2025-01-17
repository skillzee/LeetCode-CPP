class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> psOdd(n, 0), psEven(n, 0);

        psEven[0] = nums[0];
        for (int i = 1; i < n; i++) {
            psEven[i] = psEven[i - 1];
            psOdd[i] = psOdd[i - 1];
            if (i % 2 == 0) {
                psEven[i] += nums[i];
            } else {
                psOdd[i] += nums[i];
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int totalEvenSum =
                (i > 0 ? psEven[i - 1] : 0) + psOdd[n - 1] - psOdd[i];
            int totalOddSum =
                (i > 0 ? psOdd[i - 1] : 0) + psEven[n - 1] - psEven[i];
            if (totalEvenSum == totalOddSum) {
                res++;
            }
        }
        return res;
    }
};
