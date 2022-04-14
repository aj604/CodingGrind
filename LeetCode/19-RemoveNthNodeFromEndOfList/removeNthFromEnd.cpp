// My Solution to LeetCode 19 - Remove Nth Node from End of List
// leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
//
// Time - O(n) - faster than 88.38%
// Space - O(n) - less than 32.82%

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
    ListNode* removeNthFromEnd(ListNode* head, int n){
      
    }

    //Novel solution. Only iterates through list once
    //Length of vector<ListNode*> is 30 max
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(!head->next) return nullptr;
      ListNode* current = head;
      vector<ListNode*> store;
      while(current) {
        store.push_back(current);
        current = current->next;
      }
      if(n == 1) {
        store[store.size()-2]->next = nullptr;
        return head;
      }
      if(n == store.size()) return head->next;
      store[store.size()-n-1]->next = store[store.size()-n+1];
      return head;
    }
    
};