class Solution:
    def isStrong(self, n: int, a: int) -> bool: # O(log n log n)
        e = n - 1
        p = pow(a, e, n) # O(log e)
        if p != 1:
            return False

        while True:
            e >>= 1
            p = pow(a, e, n)
            if p == n - 1:
                return True
            if e & 1:
                if p == 1:
                    return True
                break

        return False

    # Miller test
    def isPrime(self, n: int) -> bool:
        return self.isStrong(n, 2) and (n < 2047 or self.isStrong(n, 3))

    def closestPrimes(self, i: int, j: int) -> list[int]:
        x = -1
        y = -1

        if i < 3:
            x = 2
            i = 3
        else:
            i += 1 if (i & 1) == 0 else 0
            while i <= j:
                if self.isPrime(i):
                    x = i
                    i += 2
                    break
                i += 2

        while i <= j:
            if self.isPrime(i):
                y = i
                i += 2
                break
            i += 2

        t = y
        while i <= j and (y - x > 2 or y == -1):
            if self.isPrime(i):
                if y == -1 or (y - x) > (i - t):
                    x = t
                    y = i
                t = i
            i += 2

        if y > 0:
            return [x, y]
        return [-1, -1]