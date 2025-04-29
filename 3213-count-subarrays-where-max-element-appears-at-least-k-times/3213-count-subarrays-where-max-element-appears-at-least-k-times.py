class Solution(object):
    def countSubarrays(self, nums, k, left=0):
        maxi = max(nums)
        res = 0
        mpp = {}
        for i in range(len(nums)):
            mpp[nums[i]] = mpp.get(nums[i], 0) + 1
            if mpp.get(maxi, 0) >= k:
                while left < len(nums) and mpp.get(maxi, 0) >= k:
                    mpp[nums[left]] -= 1
                    left += 1
            res += left
        return res