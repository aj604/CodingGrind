#include <iostream>

using namespace std;

class Node
{
  public:
    Node(){
      this->next=nullptr;
    }
    int data;
    Node *next = nullptr;
};

class LinkedList
{
  public:
    Node* head;

    LinkedList(){
      this->head = new Node();
    }
    
    friend ostream& operator<<(ostream& os, const LinkedList& ll);    
    void push(int val);
    void insertAfter(Node* node,int val);
    void insertAtEnd(int val);
    void deleteAtPosition(int val);
    void deleteValue(int val);

    int size();
    int position(int val);
    bool contains(int val);
    int nthNode(int val);
    void printList();
    
    void sort();
  private:
    Node* merge(Node* a, Node* b);
    void mergeSplit(Node* source, Node** frontRef, Node** backRef);
    void mergeSort(Node** headRef);

};
void LinkedList::sort(){
  mergeSort(&this->head);
}

void LinkedList::mergeSort(Node** headRef){
  Node* head = *headRef;
  Node* a;
  Node* b;

  if ((head == NULL) || (head->next == NULL)) return;
  
  //Split into Front / Back
  mergeSplit(head, &a, &b); //Needs &?

  mergeSort(&a); //Needs &
  mergeSort(&b);

  *headRef = merge(a, b);
}

void LinkedList::mergeSplit(Node* source, Node** frontRef, Node** backRef){
  Node* fast;
  Node* slow;
  slow = source;
  fast = source->next;

  while(fast != NULL){
    fast = fast->next;
    if (fast != NULL){
      slow = slow->next;
      fast = fast->next;
    }
  }

  *frontRef = source;
  *backRef = slow->next;
  slow->next = NULL;
}

Node* LinkedList::merge(Node* a, Node* b){
  Node* result = NULL;

  //Base Case
  if(a == NULL)
    return b;
  else if (b == NULL)
    return a;

  if(a->data <= b->data){
    result = a;
    result ->next = merge(a->next, b);
  }
  else {
    result = b;
    result->next = merge(a, b->next);
  }
  return result;
}

ostream& operator<<(ostream& os, const LinkedList& ll){
  Node* current = ll.head;
  while(current->next){
    os << current->data << " -> ";
      current = current->next;
    }
  os << current->data << "\n";
}

int LinkedList::nthNode(int val){
  Node* current = this->head;
  for(int ii = 0; ii < val; ii++){
    if(current!= nullptr)
      current = current->next;
  }
  if(current != nullptr) return current->data;
  return -1;
}

bool LinkedList::contains(int val){
  Node* current = this->head;
  while(current != nullptr){
    if(current->data == val) return true;
    current = current->next;
  }
  return false;
}

int LinkedList::position(int val){
  Node* current = this->head;
  int ii = 0;
  while(current != nullptr){
    if(current->data == val) return ii;
    current = current->next;
    ii++;
  }
  return -1;
}

int LinkedList::size(){
  Node* current = this->head;
  int ii = 0;
  while(current != nullptr){
    ii++;
    current = current->next;
  }
  return ii;
}

void LinkedList::printList(){
      Node* current = head;
      while(current->next){
        cout << current->data << " -> ";
        current = current->next;
      }
      cout << current->data << "\n";
    }

void LinkedList::push(int val){
  Node* temp = new Node();
  temp->data = val;
  temp->next = this->head;
  this->head = temp;
}

void LinkedList::insertAfter(Node* node, int val){
  Node* temp = new Node();
  temp->data = val;
  temp->next = node->next;
  node->next = temp;
}

void LinkedList::deleteAtPosition(int val){
  if(val == 0){
    this->head = this->head->next;
    return;
  }
  int ii = 1;
  Node* temp = (this->head);
  while(temp->next != nullptr){
    if(ii < val){
      ii++;
      temp = temp->next;
      continue;
    }
    if(ii == val){
      temp->next = temp->next->next;
      return;
    }
  }
  
}
void LinkedList::deleteValue(int val){
  Node* current = this->head;
  if(current->data == val){
    this->head = this->head->next;
    return;
  }
  while(current->next != nullptr){
    if(current->next->data == val){
      current->next = current->next->next;
      return;
    }
    current = current->next;
  }
}

main(){
  LinkedList* a = new LinkedList();
  LinkedList* b = new LinkedList();
  LinkedList* c = new LinkedList();
  Node* tempA = a->head;
  Node* tempB = b->head;
  Node* tempC = c->head;
  tempA->data = 1;
  tempB->data = 9;

  /*if (a->head->data < b->head->data){
    c->head->data = tempA->data;
    cout << "A > B " << a->head->data << " > " << b->head->data <<"\n";
    tempA = tempA->next;
  }
  else{
    c->head->data = tempB->data;
    cout << "A < B\n";
    tempB = tempB->next;
  }
  
  */
  for(int i = 2 ; i< 10; i++) {
    a->insertAfter(tempA, i%3);
    b->insertAfter(tempB, 10-i);
    tempA = tempA->next;
    tempB = tempB->next;
  }
  if (a->head->data > b->head->data) cout << "A > B\n";
  cout << *a;
  //cout << a->size() << "\n";
  a->sort();
  cout << *a;
    cout << a->size() << "\n";
  
}