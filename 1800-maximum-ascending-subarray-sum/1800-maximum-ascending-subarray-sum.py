class Solution:
    def maxAscendingSum(self, nums: list[int]) -> int:
        maxi = nums[0]
        n = len(nums)
        prev = nums[0]
        sum = prev
        for i in range(1, n):
            if nums[i] > prev:
                sum+=nums[i]
                prev = nums[i]
                maxi = max(sum, maxi)
            else:
                prev = nums[i]
                sum = nums[i]
        
        return maxi