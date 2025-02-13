class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heapq.heapify(nums)
        res=0

        for i in range(0, len(nums)):
            x=heapq.heappop(nums)
            if x<k:
                res+=1
                y=heapq.heappop(nums)
                heapq.heappush(nums, x*2+y)
            else:
                break

        return res