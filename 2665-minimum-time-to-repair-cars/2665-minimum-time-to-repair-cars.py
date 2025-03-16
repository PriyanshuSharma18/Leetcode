class Solution:
    def repairCars(self, r: List[int], c: int) -> int:
        return bisect_left(range(1<<47),c,key=lambda m:sum(isqrt(m//x)for x in r))