// My Solution to LeetCode 2 - AddTwoNumbers
// leetcode.com/problems/add-two-numbers
//
// Time O(n) - faster than 86.59%
// Space O(n) - less than 11.96%

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      vector<int> v1, v2;
      int carry = 0, digit = 0;
      ListNode* ret = nullptr;
      ListNode* cur1 = l1;
      ListNode* cur2 = l2;
      while(cur1 || cur2){
        if(cur1){ 
          v1.push_back(cur1->val);
          cur1 = cur1->next;
        }
        else v1.push_back(0);
        if(cur2){
          v2.push_back(cur2->val);
          cur2 = cur2->next;
        }
        else v2.push_back(0);
      }
      if(l1 || l2){
        carry = (v1[0]+v2[0]) / 10;
        digit = (v1[0]+v2[0]) % 10;
        ret = new ListNode(digit);
      }
      cur1 = ret;
      for(int ii = 1; ii < v1.size(); ii++){
        digit = (v1[ii]+v2[ii] + carry) % 10;
        carry = (v1[ii]+v2[ii] + carry) / 10;
        //cout << v1[ii] << " + " << v2[ii] << " + " << carry << " = " << v1[ii]+v2[ii]+carry << endl;
        //cout << "carry = " << carry << " digit = " << digit << endl << endl;
        cur1-> next = new ListNode(digit);
        cur1 = cur1->next;
      }
      if(carry) cur1->next = new ListNode(carry);
    return ret;
    }
};



void printList(ListNode* node){
  ListNode* current = node;
  while(current){
    if(current->next == NULL) cout << current->val << endl;
    else cout << current->val << " -> ";
    current = current->next;
  }
};

ListNode* insertFront(int x, ListNode *node){
  return new ListNode(x, node);
};

ListNode* insertBack(int x, ListNode* node){
  ListNode* current = node;
  if(current == nullptr) return new ListNode(x);
  while(current->next) current = current->next;
  current->next = new ListNode(x);
  return node;
};

main(){
  Solution test = Solution();
  ListNode* temp = new ListNode(9);
  ListNode* temp2 = new ListNode(9);
  ListNode* temp3 = nullptr;
  for(int ii = 1; ii < 7; ii++){
    temp = insertBack(9, temp);
    if( ii < 4) temp2 = insertBack(9, temp2);
    }
  printList(temp);
  printList(temp2);
  temp3 = test.addTwoNumbers(temp, temp2);
  printList(temp3);
}