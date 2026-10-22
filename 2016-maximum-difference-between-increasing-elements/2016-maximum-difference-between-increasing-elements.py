class Solution:
    def maximumDifference(self, nums: list[int]) -> int:
        n = len(nums)
        right_max = nums[n-1]
        maxi = 0
        for i in range(n-2, -1, -1):
            if (right_max - nums[i]) > maxi:
                maxi = right_max - nums[i]
            if nums[i] > right_max:
                right_max = nums[i]
        if maxi ==0:
            return -1

        return maxi

        