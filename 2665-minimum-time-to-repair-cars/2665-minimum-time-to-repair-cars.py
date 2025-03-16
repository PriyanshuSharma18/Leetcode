class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def can_repaired(time):
            cnt = 0
            for r in ranks:
                cnt += int(sqrt(time / r))
            return cnt >= cars
        
        l, r = 1, min(ranks) * cars * cars

        while l <= r:
            m = (l + r) // 2
            if can_repaired(m):
                r = m - 1
            else:
                l = m + 1
        
        return l