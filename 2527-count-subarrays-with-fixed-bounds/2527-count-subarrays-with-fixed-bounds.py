class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        count = 0
        start = -1
        mini = -1
        maxi = -1
        for i in range(len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                start = i
            if nums[i] == maxK:
                maxi = i
            if nums[i] == minK:
                mini = i
            valid = max(0, min(mini, maxi) - start)
            count += valid
        return count