#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;

class Solution {
public:
    /*
    First Pass Solution. Needs work
    faster than 27.16%
    Less memory than 43.80%
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
      ListNode* result = NULL;

      if(list1 == NULL)
        return list2;
      else if(list2 == NULL)
        return list1;

      if(list1->val <= list2->val){
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
      }
      else {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
      }
      return result;
    }

    /*ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* result = new ListNode();
      ListNode* NextResult = nullptr;
      if(list1->val <= list2->val){
        result->val=list1->val;
        result->next = &NextResult;
        list1 = list1->next;
      }
      else{
        result->val = list2->val;
        result->next = &NextResult;
        list2 = list2->next;
      }
      while(list1 != nullptr && list2 != nullptr){
        if(list1->val <= list2->val){
          NextResult.next = new ListNode(list1->val);
          NextResult = *NextResult.next;
          list1 = list1->next;
          continue;
        }
        else {
          NextResult.next = new ListNode(list2->val);
          NextResult = *NextResult.next;
          list2 = list2->next;
          continue;
        }
      }
      if(list1 != nullptr) NextResult.next = list1;
      if(list2 != nullptr) NextResult.next = list2;
      return result;
    }
    void endInsert(ListNode* currentEnd, int val){
      ListNode* node = new ListNode(val);
      //node->val = val;
      //cout<< "Node Value Inserting: " << node->val <<"\n";
      node->next = currentEnd->next;
      //currentEnd->val = val;
      currentEnd->next = node;
      //cout << "Inserted ListNode with Value " << val << "\n";
      //return node;
    }

    static void printList(ListNode* list){
      ListNode* current = list;
      while(current->next){
        cout << current->val << " -> ";
        current = current->next;
      }
      cout << current->val << "\n";
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
      ListNode* aCurrent = list1;
      ListNode* bCurrent = list2;
      ListNode* ptr = nullptr;
      if(!list1) return list2;
      if(!list2) return list1;

      ListNode* ret = nullptr;//new ListNode(-1);
              cout << "A: " << aCurrent->val << " :: ";
        printList(aCurrent);
        cout << "B: " << bCurrent->val << " :: ";
      printList(bCurrent);
      if(list1->val >= list2->val){
        ret = new ListNode(list1->val);
        ptr = list1->next;
        cout <<"A Initial Loc: " << aCurrent << "\n";
        aCurrent = list1->next;
        cout << "A Secondary Loc: " << aCurrent << "\n\n";
      }
      else{
        ret = new ListNode(list2->val);
        ptr = list2->next;
        bCurrent = list2->next;
      }


      
      while(aCurrent != nullptr && bCurrent != nullptr){
        cout << "A: " << aCurrent->val << " :: ";
        printList(aCurrent);
        cout << "B: " << bCurrent->val << " :: ";
        printList(bCurrent);
        //cout << "here";
        while(aCurrent->val > bCurrent->val){
          endInsert(ptr, aCurrent->val);
          ptr = ptr->next;
          cout <<"A Initial Loc: " << aCurrent << "\n";
          aCurrent = aCurrent->next;
          cout << "A Secondary Loc: " << aCurrent << "\n\n";
          }
        while(bCurrent->val >= aCurrent->val){
          endInsert(ptr, bCurrent->val);
          ptr = ptr->next;
          bCurrent = bCurrent->next;
        }
      }
      if(!list1) ptr->next = list2;
      if(!list2) ptr->next = list1;
      return ret;
    }
*/
};

main(){
  /*
  ListNode* a = new ListNode();
  ListNode* b = new ListNode();
  ListNode* tempA = a;
  ListNode* tempB = b;
  Solution* test = new Solution();
  for(int i = 0 ; i< 10; i++) {
    test->endInsert(tempA, i);
    test->endInsert(tempB, i);
    tempA = tempA->next;
    tempB = tempB->next;
  }
  test->printList(a);
  test->printList(b);
  ListNode* result = nullptr;

  result = test->mergeTwoLists(a, b);
  test->printList(result);
  
  ListNode a = ListNode();
  ListNode b = ListNode();
  ListNode* aPtr = &a;
  ListNode* bPtr = &b;
  ListNode* result = nullptr;
  Solution test = Solution();
  for(int ii = 1; ii < 10; ii++){
    test.endInsert(&a, ii);
    a = *a.next;
    cout << "Node Val Post Insert: " << aPtr->val <<"\n";
    //bPtr = test.endInsert(bPtr, ii);
    cout << "Current List A:\n";
    test.printList(aPtr);
    //cout << "Current List B:\n";
    //test.printList(&b);
  }
  //test.printList(&a);
  //test.printList(&b);
  //result = test.mergeTwoLists(&a, &b);
  //test.printList(result);
  */
}