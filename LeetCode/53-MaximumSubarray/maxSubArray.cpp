#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums){
      int sum = nums[0];
      int lastPositiveStreak = 0;
      int negativeStreak = 0;
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
          if(negativeStreak > lastPositiveStreak){
            sum = nums[ii];
            lastPositiveStreak = nums[ii];
            negativeStreak = nums[ii];
            continue;
          }
          
        }
        if(nums[ii]>=0){
          lastPositiveStreak += nums[ii];
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
  cout << sumVector(input3) << endl << test.maxSubArray(input4);
  
  assert(test.maxSubArray(input2) == 99);
  assert(test.maxSubArray(input4) == 23);
  assert(test.maxSubArray(input5) == 1);
  //cout << test.maxSubArray(input);
}