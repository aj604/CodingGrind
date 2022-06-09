# My Solution to LeetCode 169 - Majority Element
# leetcode.com/problems/majority-element/
# 
# Time O(n) - Faster than 82.95%
# Space O(1) - Less than 98.70%

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority = len(nums) / 2
        store = Counter(nums)
        for a in store:
            if store[a] >= majority:
                return a