#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  ListNode* input = new ListNode();
  ListNode* input2 = new ListNode();
  for(int ii = 1; ii < 10; ii++){
    input = insertFront(ii, input);
    input2 = insertBack(ii, input2);
  }
  printList(input);
  printList(input2);  
}