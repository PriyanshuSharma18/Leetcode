class Solution:
    def checkValidCuts(self, _: int, a: List[List[int]]) -> bool:
        return any(sum(map(le,accumulate([0,*b],max),a))>2
            for a,b in starmap(zip,map(sorted,map(zip,*zip(*[iter(zip(*a))]*2))))
        )