class Solution:
    def minMoves(self, nums: list[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (2 * limit + 2)

        for i in range(n // 2):
            a = nums[i]
            b = nums[n - 1 - i]
            lo = min(a, b)
            hi = max(a, b)

            # Base: 2 moves for all T
            # [lo+1, lo+hi-1]: save 1 move
            diff[lo + 1]         += 1
            diff[lo + hi]        -= 1

            # [lo+hi, lo+hi]: save 2 moves (0 moves needed)
            diff[lo + hi]        += 2
            diff[lo + hi + 1]    -= 2

            # [lo+hi+1, hi+limit]: save 1 move
            diff[lo + hi + 1]    += 1
            diff[hi + limit + 1] -= 1

        # n = n/2 pairs * 2 moves each = base cost
        # find max savings
        curr = 0
        max_save = 0
        for T in range(2, 2 * limit + 1):
            curr += diff[T]
            max_save = max(max_save, curr)

        return n - max_save