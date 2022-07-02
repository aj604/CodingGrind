# My Solution to LC 26 - Remove duplicates from sorted array
#
# O(n log n) - Faster than 89.32%
# Space - O(n) - Less than 15.61%
class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    nums[:] = sorted(set(nums))
    return len(nums)