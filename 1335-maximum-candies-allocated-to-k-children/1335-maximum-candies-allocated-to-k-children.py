class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def get_c(c, k):
            for x in candies:
                k-=x//c
                if k<=0: 
                    return True
            return False
        Sum=sum(candies)
        if Sum<k: 
            return 0
        l, r=1, Sum//k
        while l<r:
            m=(l+r+1)//2
            if get_c(m, k): 
                l=m
            else: 
                r=m-1
        return l
        
        