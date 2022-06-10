# Initial Solution to LC 111 - minimum depth of binary tree
#
#
# Time - O(n^2) - Revisit using DFS
# Space - O(n)

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if(root == None): return 0
        leftDepth = self.minDepth(root.left)
        if(leftDepth == 0): return self.minDepth(root.right) + 1
        rightDepth = self.minDepth(root.right)
        if(rightDepth == 0): return leftDepth + 1
        return min(leftDepth, rightDepth) + 1