class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        before, after = [], [] # stores nums before and after pivot

        for num in nums: # add num to corresponding list, neither if equals pivot
            if num < pivot:
                before.append(num)
            elif num > pivot:
                after.append(num)

        equal_pivot = len(nums) - len(before) - len(after) # count of nums equal to pivot
        return before + [pivot] * equal_pivot + after # combine lists, make list for nums equal to pivot