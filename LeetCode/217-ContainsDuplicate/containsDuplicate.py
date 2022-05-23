# My Solution to LeetCode 217
# https://leetcode.com/problems/contains-duplicate/
#
# Time - O(n) - Faster than 94.99%
# Space - O(1) - Better than 93.79%
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        for a in set(Counter(nums).values()):
            if a > 1:
                return True
        return False