class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        count = Counter(int(c) for c in num)
        total = sum(int(c) for c in num)
        MOD = 10**9 + 7
        n = len(num)
        @cache
        def DFS(i, odd, even, balance):
            if odd == 0 and even == 0 and balance == 0:
                return 1
            if i < 0 or odd < 0 or even < 0 or balance < 0:
                return 0
            res = 0
            for j in range(0, count[i] + 1):
                res += comb(odd, j) * comb(even, count[i] - j) * DFS(i - 1, odd - j, even - count[i] + j, balance - i * j)
            return res % MOD
        return 0 if total % 2 else DFS(9, n - n // 2, n // 2, total // 2)