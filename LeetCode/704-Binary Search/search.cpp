// My Solution to LeetCode 704 - Binary Search
// leetcode.com/problems/binary-search
//
// Time - O(log(n)) Faster than 88.90%
// Space - O(1)  Less Than 92.44%
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  private:
    int search(int start, int end, vector<int>& nums, int target){
      int mid = end-start;
      mid = mid / 2;
      mid += start;
      if(nums[mid] == target) return mid;
      if(start >= end) return -1;
      if(nums[mid] > target){
        return search(start, mid, nums, target);
      }
      return search(mid + 1, end, nums, target);
    }
  public:   
    int search(vector<int>& nums, int target) {
      return search(0, nums.size()-1, nums, target);
    }
};

main(){
  vector<int> input = {-1};
  Solution test = Solution();
  cout << test.search(input, 2);
}