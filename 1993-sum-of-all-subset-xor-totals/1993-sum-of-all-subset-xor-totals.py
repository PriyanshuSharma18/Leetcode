class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(1 << n):
            x = 0
            for j in range(n):
                if (1 << j) & i:
                    x ^= nums[j]
            res += x
        return res