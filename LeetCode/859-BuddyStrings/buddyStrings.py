# My Solution to LeetCode 859 - Buddy Strings
# leetcode.com/problems/buddy-strings/submissions/
#
# Time - O(n) - Faster than 95.70%
# Space - (1) - Less than 61.31%
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        wrongLetters = {}
        wrongCount = 0

        for i in range(len(s)):
            if s[i] != goal[i]:
                if wrongCount == 2:
                    return False
                wrongCount += 1
                wrongLetters[i] = s[i]
                
        if wrongCount == 2:
            wrongIndex = list(wrongLetters.keys())
            ret = s[0:wrongIndex[0]] + wrongLetters[wrongIndex[1]] + s[wrongIndex[0]+1:wrongIndex[1]] + wrongLetters[wrongIndex[0]] + s[wrongIndex[1]+1:]
            if goal == ret:
                return True
            
        elif s == goal:
            letterCount = Counter(s)
            for i in letterCount.values():
                if i >= 2:
                    return True
        return False