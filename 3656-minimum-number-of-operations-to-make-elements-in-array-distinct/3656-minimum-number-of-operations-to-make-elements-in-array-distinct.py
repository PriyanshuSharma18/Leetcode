class Solution:
    def minimumOperations(self, nums):
        operations = 0
        
        while nums:
            unique_elements = set(nums)

            if len(unique_elements) == len(nums):
                break
            
            nums = nums[min(3, len(nums)):]
            operations += 1
        
        return operations