#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
};
/*Solution::mergeKLists(vector<ListNode*>& lists){
      ListNode* current = nullptr;
      ListNode* res = nullptr;
      ListNode* resIter = nullptr;
      int loc = 0;
      while(!lists.empty()){
        current = lists[0];
        for(int ii = 1; ii < lists.size(); ii++){
          if(lists[ii]->val < current->val){
            loc = ii;
            current = lists[ii];
          }
        } 
        if(!res){
          res = lists[loc];
          resIter=res;
          if(res->next) lists[loc]=res->next;
          else lists.erase(lists.begin()+loc);
        }
        else {
          resIter->next = lists[loc];
          if(res->next) lists[loc]=res->next;
          else lists.erase(lists.begin()+loc);
        }
      }
      return res;
    }
/*
    //mergeTwoLists solution 
    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2){
      if(list1 == NULL) return list2;
      if(list2 == NULL) return list1;

      ListNode* result = NULL;
      ListNode* current = NULL;

      if(list1->val < list2->val){
        result = list1;
        list1 = list1->next;
      } else {
        result = list2;
        list2 = list2->next;
      }
      current = result;
      
      while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
          current->next = list1;
          list1 = list1->next;
        }
        else{
          current->next = list2;
          list2 = list2->next;
        }
        current = current->next;
      }
      if(list1 == NULL) current->next = list2;
      if(list2 == NULL) current->next = list1;
      
      return result;
    }  
    
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2){
      ListNode* result = NULL;

      if(list1 == NULL)
        return list2;
      else if(list2 == NULL)
        return list1;

      if(list1->val <= list2->val){
        result = list1;
        result->next = mergeTwoListsRecursive(list1->next, list2);
      }
      else {
        result = list2;
        result->next = mergeTwoListsRecursive(list1, list2->next);
      }
      return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        if(lists.size()==1) return lists[0];
        ListNode * res = lists[0];
        for(int ii = 1; ii < lists.size(); ii++){
            res = mergeTwoListsIterative(lists[ii], res);
        }
        return res;
        
    }
    */
