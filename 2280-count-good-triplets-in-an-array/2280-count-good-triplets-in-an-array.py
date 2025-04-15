class Fenwick:
    def __init__(self, n):
        self.tree = [0] * (n + 1)
    def update(self, k, x):
        k += 1
        while k < len(self.tree):
            self.tree[k] += x
            k += k & -k
    def query(self, k):
        total = 0
        k += 1
        while k > 0:
            total += self.tree[k]
            k -= k & -k
        return total

class Solution(object):
    def goodTriplets(self, nums1, nums2):
        n = len(nums1)
        total = 0
        mpp = [0] * n
        for i in range(n):
            mpp[nums1[i]] = i
        fw = Fenwick(n)
        for i in nums2:
            idx = mpp[i]
            left = fw.query(idx)
            total_inner = fw.query(n - 1)
            right = (n - 1 - idx) - (total_inner - left)
            total += left * right
            fw.update(idx, 1)
        return total