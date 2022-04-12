#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;

class Solution {
public:
    //My Solution for LeetCode 125
    //https://leetcode.com/problems/valid-palindrome
    //
    //Time - O(n) - faster than 87.89%
    //Space - O(1) - less than 89.79%
    //
    static bool isPalindrome(string s){
      auto front = s.begin(), back = s.end();
      back--;
      while(front < back){
        while(!isalnum(*front) && front < back) front++;
        while(!isalnum(*back) && front < back) back--;
        if(tolower(*front) != tolower(*back)) return false;
        front++;
        back--;
      }
      return true;
    }

    /*
    //Does not handle whitespace in string
    bool isPalindrome(string s) {
      if(s.length() <= 2) return true;
      for(int ii = 0; ii < s.length()/2; ii++){
        if(s[ii] != s[s.length-1-ii]) return false;
      }
      return true;
    }
    */
};

main(){
  cout << Solution::isPalindrome("A man, a plan, a canal: Panama") << "\n";
}