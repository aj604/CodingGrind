// My Solution to LeetCode 14 - Longest Common Prefix
// leetcode.com/problems/longest-common-prefix;
//
// Time - O(m*n) where n is the number of strings and m is the minimum string length
// Time - Faster than 87.48%
// Space - O(m) - Less than 78.34%

#include <iostream>
#include <cmath>
#include <string>

class Solution {
public:
  int longestCommonPrefix(vector<string>& strs) {
    int maxLength = 201;
    string max = "";
    char current = ' ';
    for(int ii = 0; ii < strs.size(); ii++)
      maxLength = maxLength > strs[ii].length() ? strs[ii].length() : maxLength;
    for(int ii = 0; ii < maxLength; ii++){
      current = strs[0][ii];
      for(int jj = 1; jj < strs.size(); jj++){
        if(strs[jj][ii] != current) return max;
      }
      max += strs[0][ii];
    }
    return max;
  }
}