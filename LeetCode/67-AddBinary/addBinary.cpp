/*
My Solution to LeetCode 67 - Add Binary
leetcode.com/problems/add-binary

Time O(n) - Faster than 100.00% 
Space O(n+m) - Less than 99.73%
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      int aIter = a.length()-1, bIter = b.length()-1;
      string reversedRet = "";
      char remainder = '0';
      for(aIter, bIter; aIter >= 0 || bIter >= 0; aIter--, bIter--){
        if(aIter >= 0 && bIter >= 0){
          //Both 1
          if(a[aIter] == '1' && b[bIter] == '1'){ 
             if(remainder == '1'){
               reversedRet += '1'; //Dont reset Remainder here
             } else {
              reversedRet += '0';
               remainder = '1';
            }
          }
          // Only 1 1 
          else if(a[aIter] == '1' || b[bIter] == '1'){ 
            if(remainder == '1'){
              reversedRet += '0';
              remainder = '1';
            }
            else{
              reversedRet += '1';
            }
          }
          //Both 0
          else {
            if(remainder == '1'){
              reversedRet += '1';
              remainder = '0';
            }
            else{
              reversedRet += '0';
            }
          }
        }

        //One input longer than the other
        else if(aIter >= 0){
          while(aIter >= 0){
            if(remainder == '1'){
              if(a[aIter] == '1'){
                reversedRet += '0';
                aIter--;
              } else {
                reversedRet += '1';
                remainder = '0';
                aIter--;
              }
            } else {
              while(aIter >= 0){
                reversedRet += a[aIter];
                aIter--;
              }
            }
          }
        }
        else if(bIter >= 0){
          while(bIter >= 0){
            if(remainder == '1'){
              if(b[bIter] == '1'){
                reversedRet += '0';
                bIter--;
              } else {
                reversedRet += '1';
                remainder = '0';
                bIter--;
              }
            } else {
              while(bIter >= 0){
                reversedRet += b[bIter];
                bIter--;
              }
            }
          }
        }
        
      }
      if(remainder == '1') reversedRet += '1';
      reverse(reversedRet.begin(), reversedRet.end());
      return reversedRet;
    }
};

main(){
  Solution test = Solution();
  cout << test.addBinary("1111111", "111");
  assert(test.addBinary("110010", "10111") == "1001001");
}