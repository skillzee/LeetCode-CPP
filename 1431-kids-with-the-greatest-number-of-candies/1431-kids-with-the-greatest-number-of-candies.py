class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        n = len(candies)
        result : list[bool] = [False]*n 
        maxi = max(candies)
        for i in range(0, n):
            if (candies[i] + extraCandies) >= maxi:
                result[i] = True
        return result
        