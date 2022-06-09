# My Solution to LeetCode 104 - Maximum Depth Of Binary Tree
# leetcode.com/problems/maximum-depth-of-binary-tree/
#
# Time O(n) - Faster than 83.40%
# Space O(n) - Less than 22.40%
def maxDepth(self, root: Optional[TreeNode]) -> int:
  if(root == None): return 0
  return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1