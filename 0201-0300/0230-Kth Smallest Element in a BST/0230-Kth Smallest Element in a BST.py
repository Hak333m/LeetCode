# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        curr = root
        while curr:
            if curr.left is None:
                k -= 1
                if k == 0:
                    return curr.val
                curr = curr.right
            else:
                prev = curr.left
                while prev.right and prev.right != curr:
                    prev = prev.right
                    
                if prev.right is None:
                    prev.right = curr
                    curr = curr.left
                else:
                    k -= 1
                    if k == 0:
                        return curr.val
                    prev.right = curr
                    curr = curr.right
        return -1
