// My C++ Solutions to LC 241 - Contains Duplicates
// https://leetcode.com/problems/contains-duplicate/


#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Solution implemented using map
    // Overkill due to counting being unneccesary. If second occurence return true
    // Only need to track numbers Ive seen, not how many time ive seen them
    //
    // Time O(n) - Faster than 96.41%
    // Space O(n) - Less than 63.20%
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> store;
      for(auto i : nums){
        if(store.find(i) != store.end()) store[i]++;
        else store[i] = 1;
        if(store[i] > 1) return true;
      }
      for(const auto &i : store){
        if(i.second > 1) return true;
      }
      return false;
    }


    // Solution implemented using set
    // Tries to insert each val into the set
    // If insert fails its second occurence, so return true
    // Set more expensive than map, so unfortunately not faster
    // Time O(n) - Faster than 95.08%
    // Space O(n) - Less than 51.63%
    bool containsDuplicateV2(vector<int>& nums) {
      unordered_set<int, int> store;
      for(auto i : nums){
        auto [it, notInSet] = store.insert(i);
        if(!notInSet) return true;
      }
      return false;
    }


    // Sorting provides an interesting approach to the problem
    // Although traditionally too expensive to justify, sorting allows you to not
    // construct or perform expensive inserts with the data, and instead allows
    // finding of duplicates inline
    //
    // Time - O(nlog(n)) - Faster than 88.42%
    // Space - O(1) - Less than 80.16%
    bool containsDuplicateV3(vector<int>& nums) {
      sort(nums.start(), nums.end());
      for(int ii = 1; ii < nums.size(); ii++){
        if(nums[ii] == nums[ii-1]) return true;
      }
      return false;
    }
};