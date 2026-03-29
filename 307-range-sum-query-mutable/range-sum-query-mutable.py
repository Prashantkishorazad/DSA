class NumArray:

    def __init__(self, nums):
        self.n = len(nums)
        self.bit = [0] * (self.n + 1)
        self.nums = nums[:]
        
        # build BIT
        for i in range(self.n):
            self._updateBIT(i, nums[i])

    def _updateBIT(self, index, delta):
        index += 1
        while index <= self.n:
            self.bit[index] += delta
            index += index & -index

    def update(self, index, val):
        delta = val - self.nums[index]
        self.nums[index] = val
        self._updateBIT(index, delta)

    def _query(self, index):
        index += 1
        s = 0
        while index > 0:
            s += self.bit[index]
            index -= index & -index
        return s

    def sumRange(self, left, right):
        return self._query(right) - self._query(left - 1)