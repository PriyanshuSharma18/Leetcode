
class Solution:
    def getLongestSubsequence(self, w: List[str], g: List[int]) -> List[str]:
        return [x for i, x in enumerate(w) if not i or g[i] != g[i-1]]
