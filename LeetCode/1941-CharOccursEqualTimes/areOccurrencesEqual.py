# My Submission to LeetCode 1941 
# https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/submissions/
#
# Time Complexity O(n+26) 
# Space Complexity O(1)
class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
      store = [0] * 26 # a -> 0, b->1 z-> 25  store[0] = 0, store[25] 
      count = 0  
      for letter in str:
        store[ord(letter)-ord('a')]++ # store[letter]++ store[a]
        count = max(count, store[ord(letter)-ord('a')])
      for i in len(store):
        if store[i] != 0 && store[i] != count:
          return false
      return true
