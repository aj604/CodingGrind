/*
C++ Solution to LeetCode TwoSum Problem
https://leetcode.com/problems/two-sum/

O(n) Time - Better Than 95.36% of Submissions
O(n) Space - Less Than 28.96% of Submissions
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

class Solution {
public:
  static std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> past;

    for(int ii = 0; ii < nums.size(); ii++){
      int numberToFind = target - nums[ii];
      if(past.find(numberToFind) != past.end()){
        return {past[numberToFind], ii};
      }
      past[nums[ii]] = ii;    
    }
    return {-1,-1};
  }
};

int main() {
  std::vector<int> inputVec = {2,1,3,9,2,3,5};
  int target = 14;
  std::vector<int> result = Solution::twoSum(inputVec, 14);
  assert(inputVec[result[0]] + inputVec[result[1]] == target);  
};