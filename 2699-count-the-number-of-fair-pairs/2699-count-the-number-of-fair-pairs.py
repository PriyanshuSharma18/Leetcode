class Solution(object):
    def countAtMost(self, nums, comp):
        ans = 0
        j = len(nums) - 1
        for i in range(len(nums)):
            while i < j and nums[i] + nums[j] > comp:
                j -= 1
            if i < j:
                ans += j - i
        return ans

    def countFairPairs(self, nums, lower, upper):
        nums.sort()
        return self.countAtMost(nums, upper) - self.countAtMost(nums, lower - 1)