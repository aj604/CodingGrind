// My Solution to Leetcode - 9 - Palindrome Number;
// leetcode.com/problems/palindrome-number;
//
// Time - O(log(n)) - faster than 90.76%
// Space - O(1) - less than 91.72%

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    //Much better solution
    //Iterates through list and creates reverses
    //
    bool isPalindrome(int x){
      if(x<0) return false;
      int temp = x, rev = 0;
      while(temp){
        rev = rev * 10 + temp % 10;
        temp /= 10;
      }
      return x == rev;
    }


    //Possible the worst possible solution?
    //faster than 5.81% less than 8.05%
    /*
    int isPalindrome(int x){
      if(x < 0) return false;
      vector<int> store;
      int digit = 0;
      int size;
      while(x > 0){
        store.push_back(x%10);
        x /= 10;
      }
      size = store.size();
      for(int ii = 0; ii < size/2; ii++){
        if(store[ii] != store[size-1-ii]) return false;
      }
      return true;
    }
    */
};

main(){
  Solution test = Solution();
  if(test.isPalindrome(121)) cout << "True" << endl;
  else cout << "False\n";
}