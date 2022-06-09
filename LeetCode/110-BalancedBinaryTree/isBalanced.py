# My Solution to LeetCode 110 - Balanced Binary Tree
# leetcode.com/problems/balanced-binary-tree
#
# Time - O(n^2) - Faster than 70.21%
# Space - O(1) - Less than 60.14%
#
# Revisit after studying DFS
#
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> int:
        if (root == None):
            return True
        if(root.left == None and root.right == None):
            return True
        if(root.left == None or root.right == None):
            if(max(self.treeDepth(root.left), self.treeDepth(root.right)) > 1):
                return False
            return True
        if(abs(self.treeDepth(root.left) - self.treeDepth(root.right)) <= 1 
          and self.isBalanced(root.left) 
          and self.isBalanced(root.right)):
            return True
        return False
        
        
    def treeDepth(self, root: Optional[TreeNode]) -> int:
        if(root == None):
            return 0
        return max(self.treeDepth(root.left), self.treeDepth(root.right)) + 1


    #Originally misinterpreted the question and implemented isFull
    def isFull(self, root: Optional[TreeNode]) -> bool:
        if(self.treeDepth(root.left) == 1 and self.treeDepth(root.right) == 1):
            return True
        if(root.left == None or root.right == None):
            return False
        return self.isFull(root.left) and self.isFull(root.right)