class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        freq_dict = {}
        n = len(nums)
        for i in range(0, n):
            freq_dict[nums[i]] = freq_dict.get(nums[i], 0)+1

        for item in freq_dict:
            if freq_dict[item] > 1:
                return True

        return False
        