class Solution:
    def minimumLength(self, s: str) -> int:
        c = Counter(s)
        res = 0
        for k,v in c.items():
            if v > 2:
                if v%2 == 0:
                    res+=2
                else:
                    res+=1
            else:
                res+=v
        return res