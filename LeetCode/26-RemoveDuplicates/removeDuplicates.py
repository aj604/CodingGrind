# My Solution to LC 26 - Remove duplicates from sorted array
#
# O(n log n) - Faster than 89.32%
# Space - O(n) - Less than 15.61%
# Mainly a cheeky python solution, much more efficient to do it in line
class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    nums[:] = sorted(set(nums))
    return len(nums)