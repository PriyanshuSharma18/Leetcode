class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total_xor = 0
        for num in nums:
            total_xor |= num  
        return total_xor * (1 << (len(nums) - 1))  