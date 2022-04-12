// My Solutions to LeetCode 242 - Valid Anagram
// leetcode.com/problems/valid-anagram/
//
// Time - O(n) - Faster than 100.00%;
// Space - O(1) Less than 94.25%;
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool isAnagram(string s, string t){
      if(s.length() != t.length()) return false;
      int store[26] = {0};
      for(int ii = 0; ii < s.length(); ii++){
        store[s[ii] - 'a']++;
        store[t[ii] - 'a']--;
      }
      for(int ii = 0; ii < 26; ii++) if (store[ii]) return false;
      return true;
    }

    /*
    static bool isAnagram(string s, string t){
      if(s.length() != t.length()) return false;
      unordered_map<char, int> store;
      for(auto a : s){
        if(store.find(a) == store.end()){
          store[a] = 1;
          continue;
        }
        store[a]++;
      }
      for(auto a : t){
        if(store.find(a) == store.end()) return false;
        if(store[a] < 1) return false;
        store[a]--;
      }
      for(auto a : store) if(a.second > 0) return false;
      return true;
    }
    */
};

main(){
  Solution::isAnagram("cat", "tac");
}