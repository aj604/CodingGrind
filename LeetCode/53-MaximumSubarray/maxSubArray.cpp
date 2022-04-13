// Incorrect Solution for LeetCode 53
// Fails case where it needs to save single negative sub array
//
//
//
//


#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums){
      int sum = nums[0];
      int lastPositiveStreak = nums[0] > 0 ? nums[0] : 0;
      int negativeStreak = nums[0] > 0 ? 0 : nums[0];
      if(nums.size() == 1) return nums[0];
      for(int ii = 1; ii < nums.size(); ii++){
        
        //immediately account for adding next element
        sum += nums[ii];
        //Accounts for negative Sums
        //Acts as reset for subarray
        //if total sum can be increased by reseting subarray, always discard previous
        if(nums[ii] > sum) {
          sum = nums[ii];
          lastPositiveStreak = nums[ii];
          if(nums[ii] > 0) negativeStreak = 0;
          else negativeStreak = nums[ii];
          continue;
        }
        if(nums[ii] < 0){
          negativeStreak += nums[ii];
          if(abs(negativeStreak) >= lastPositiveStreak){
            if(nums[ii] > sum){
              sum = nums[ii];
              lastPositiveStreak = nums[ii];
              negativeStreak = nums[ii];
              continue;
            }
            vector<int> temp = {nums.begin()+ii, nums.end()};
            sum = max(sum, maxSubArray(temp));
          }
          
        }
        if(nums[ii]>=0){
          if(nums[ii] > abs(negativeStreak)){
            lastPositiveStreak += nums[ii];
          }
          else{
            vector<int> temp = {nums.begin()+ii, nums.end()};
            sum = max(sum, maxSubArray(temp));
            break;
          }
        }
      }
      return sum;
    }
};
static int sumVector(vector<int> nums){
  int sum = 0;
  for(auto a : nums) sum += a;
  return sum;
};

main(){
  Solution test = Solution();
  vector<int> input = {99, -1, -1, -1, -1, -1, -1, 99};
  vector<int> input2 = {4,-1,-2,-2,-2,99};
  vector<int> input3 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> input4 = {5, 4, -1, 7, 8};
  vector<int> input5 = {1};
  vector<int> input6 = {-1, -2};
  cout <<  test.maxSubArray(input6);

  assert(test.maxSubArray(input) == sumVector(input));
  assert(test.maxSubArray(input2) == 99);
  assert(test.maxSubArray(input3) == 6);
  assert(test.maxSubArray(input4) == 23);
  assert(test.maxSubArray(input5) == 1);
}