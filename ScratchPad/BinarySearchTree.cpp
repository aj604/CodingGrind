#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
  public:
    friend class BinarySearchTree;
    int data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node(int val);
    Node(const Node& tree);

  private:
    void insert(int val);
    int size();
    int depth();
    vector<string> stringSplit(const string& str);
    string print();
    void printBT();
    void printBT(const string& prefix, bool isLeft);
};

class BinarySearchTree 
{
  public:
    unique_ptr<Node> root;
    BinarySearchTree();
    BinarySearchTree(int val);
    BinarySearchTree(const BinarySearchTree& tree);

    void insert(int val);
    int size();
    int depth();
    void print();
    
};
Node::Node(int val){
  data = val;
  left = NULL;
  right = NULL;
}

Node::Node(const Node& tree){
  data = tree.data;
  if(left) left = make_unique<Node>(*tree.left);
  if(right) right = make_unique<Node>(*tree.right);
}

void Node::insert(int val){
  if(val > this->data){
    if(right == NULL) {
      right = make_unique<Node>(val);
      return;
    }
    right->insert(val);
  }
  else {
    if(left == NULL){
      left = make_unique<Node>(val);
      return;
    }
    left->insert(val);
  }
}

int Node::size(){
  if(left == NULL && right == NULL) return 1;
  if(left != NULL && right != NULL) return 1 + left->size() + right->size();
  if(left == NULL) return 1 + right->size();
  return 1 + left->size();
}

int Node::depth(){
  if(left == NULL && right == NULL) return 1;
  if(left != NULL && right != NULL) return 1 + max(left->depth(), right->depth());
  if(left == NULL) return 1 + right->depth();
  return 1 + left->depth();
}

void Node::printBT(const string& prefix, bool isLeft){
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << this->data << endl;

    if(left != NULL && right != NULL){
      left->printBT(prefix + (isLeft ? "│   " : "    "), true);
      right->printBT(prefix + (isLeft ? "│   " : "    "), false);
      return;
    }
  
    if(left != NULL) left->printBT(prefix + (isLeft ? "│   " : "    "), false);
    if(right != NULL) right->printBT(prefix + (isLeft ? "│   " : "    "), false);
}

void Node::printBT(){
  this->printBT("", false);
}

unique_ptr<Node> Node::rebalance(){
  if(left == NULL && right == NULL){
    return &this;
  }
  if(left != NULL && right == NULL){
    if(left.size() == 1) return %this;
    left->right = move(this);
  }
  if(right != NULL && left == NULL && right.size() == 1) return &this;
}

BinarySearchTree::BinarySearchTree(){
  root = NULL;
}

BinarySearchTree::BinarySearchTree(int val){
  root = make_unique<Node>(val);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree){
  root = make_unique<Node>(*tree.root);
}

void BinarySearchTree::insert(int val){
  if(root == NULL) root = make_unique<Node>(val);
  else root->insert(val);
  if(abs(root->left->size()-root->right->size) > 1)
    rebalance()
}
int BinarySearchTree::size(){
  if(root == NULL) return 0;
  return root->size();
}
int BinarySearchTree::depth(){
  if(root == NULL) return 0;
  return root->depth();
}
void BinarySearchTree::print(){
  root->printBT();
}

void BinarySearchTree::rebalance(){
  root = move(root.rebalance());
}

main(){
  BinarySearchTree emptyTree = BinarySearchTree();
  BinarySearchTree tree = BinarySearchTree(4);
  for(int ii = 1; ii < 10; ii++) emptyTree.insert(ii);
  cout <<"Depth: "<< emptyTree.depth() <<" Size: " << emptyTree.size() << "\n";
  emptyTree.print();  
}