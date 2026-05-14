class Solution:
    def isGood(self, nums: list[int]) -> bool:
        n = max(nums)
        base = list(range(1, n + 1)) + [n]  # [1,2,...,n-1,n,n]
        return sorted(nums) == sorted(base)