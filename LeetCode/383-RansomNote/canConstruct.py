# My Solution to LeetCode 383
# leetcode.com/problems/ransom-note
#
# Time - O(n) - Faster than 85.09%
# Space - O(1) - Less than 93.92%
#

from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
      store = Counter(magazine)  
      for a in ransomNote:
        if a in store and store[a] > 0:
          store[a] -=1
        else:
          return False
      return True


test = Solution()
assert(test.canConstruct("a","b") == False)
assert(test.canConstruct("abc","abc") == True)
assert(test.canConstruct("aaabbbccc","abc") == False)