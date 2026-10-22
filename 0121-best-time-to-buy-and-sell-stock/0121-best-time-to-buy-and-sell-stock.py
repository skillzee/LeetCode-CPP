class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        maxi = 0
        right_max = [0] * n # [0, 0, 0]
        right_max[n-1] = prices[n-1]
        for i in range(n-2, -1, -1):
            if prices[i] >= right_max[i+1]:
                right_max[i] = prices[i]
            else:
                right_max[i] = right_max[i+1]
        

        for i in range(0, n):
            profit = right_max[i] - prices[i]
            if(profit>maxi):
                maxi = profit


        return maxi

        