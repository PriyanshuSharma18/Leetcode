# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not postorder:
            return None
        node = TreeNode(preorder[0])
        idx = postorder.index(preorder[1]) if len(preorder)>1 else 0
        l = idx+1
        node.left = self.constructFromPrePost(preorder[1:l+1],postorder[:l])
        node.right = self.constructFromPrePost(preorder[l+1:],postorder[l:-1])
        return node