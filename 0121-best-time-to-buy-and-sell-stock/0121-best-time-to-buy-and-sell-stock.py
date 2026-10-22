class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        right_max = prices[n-1]
        maxi = 0
        for i in range(n-2, -1, -1):
            if (right_max - prices[i]) > maxi:
                maxi = right_max - prices[i]
            if prices[i] > right_max:
                right_max = prices[i]
        return maxi