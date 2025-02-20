class Solution:
    def findDifferentBinaryString(self, nums):
        seen = set(nums)
        n = len(nums)

        for i in range(1 << n):  
            binary = format(i, '0' + str(n) + 'b')
            if binary not in seen:
                return binary
        return ""