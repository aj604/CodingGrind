/*
My Solution for the Valid Parentheses LeetCode Problem
https://leetcode.com/problems/valid-parentheses/

V1 was slow so I refactored to V2

V1 Time: O(n) faster than 35.01%
V1 Space: O(n) less than 9.96%

V2 Time: O(n) faster than 100%
V2 Space: O(n) less than 51.21%
*/
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;


class Solution {
public:
    //very slow result on LC, need to refactor
    static bool isValidV1(string s) {
      std::stack<int> parentheses;
      unordered_set<char> open = {'(', '{', '['};
      unordered_set<char> close = {')', '}', ']'};
      //All Valid Parentheses strings will be even length
      if(s.length() % 2 != 0){
        return false;
      }
      for(char current : s){
        if(open.find(current) != open.end()){
          parentheses.push(current);
          continue;
        }
        if(close.find(current) != close.end()){
          //If stack empty and current is a close, fail
          if(parentheses.empty()){
            return false;
          }
          char top = parentheses.top();
          if(current == ')' && top == '('){
            parentheses.pop();
            continue;
          }
          if(current == '}' && top == '{'){
            parentheses.pop();
            continue;
          }
          if(current == ']' && top == '['){
            parentheses.pop();
            continue;
          }
        return false;
        }       
      }
      if(parentheses.empty()) return true;
      return false;
    }

    //Same logic as previous, skips set checks, and uses switch
    static bool isValidV2(string s) {
      std::stack<int> parentheses;
      if(s.length() % 2 != 0){
        return false;
      }
      for(char current : s){
        switch(current){
          case '(':
            parentheses.push(current);
            break;
          case '{':
            parentheses.push(current);
            break;
          case '[':
            parentheses.push(current);
            break;
          case ')':
            if(parentheses.empty()) return false;
            if('(' == parentheses.top()){
              parentheses.pop();
              break;
            }
          return false;
          case '}':
            if(parentheses.empty()) return false;
            if('{' == parentheses.top()){
              parentheses.pop();
              break;
            }
            return false;
          case ']':
            if(parentheses.empty()) return false;
            if('[' == parentheses.top()){
              parentheses.pop();
              break;
            }
            return false;
          default:
            return false;
        }
      }
      if(parentheses.empty()) return true;
      return false;
    }
};

main(){
  std::cout <<"V1:\n"<< Solution::isValidV1("({{{{}}}))") << "\n";
  std::cout <<"V2:\n"<< Solution::isValidV2("({{{{}}}))") << "\n";
}

