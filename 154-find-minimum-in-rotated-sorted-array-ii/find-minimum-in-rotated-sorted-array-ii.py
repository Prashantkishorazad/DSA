class Solution:
    def findMin(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid] > nums[right]:
                left = mid + 1      # min in right half
            elif nums[mid] < nums[right]:
                right = mid         # min in left half (mid included)
            else:
                right -= 1          # can't tell → shrink right safely

        return nums[left]