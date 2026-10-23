class Solution:
    def maximumWealth(self, accounts: list[list[int]]) -> int:
        n = len(accounts)
        m = len(accounts[0])
        max = 0
        for i in range(0, n):
            sal = 0
            for j in range(0, m):
                sal+=accounts[i][j]
            if sal > max:
                max = sal
        return max
        