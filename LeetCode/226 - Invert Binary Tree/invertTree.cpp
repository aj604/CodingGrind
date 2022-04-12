//My Solution for LeetCode 226 - Invert Binary Tree
//leetcode.com/problems/invert-binary-tree/
//
// Time - O(n) - Faster than 100.00%
// Space - O(n) - Less than 38.07%
//


#include <cstddef>
#include <utility>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL){
          if(root->left != NULL || root->right != NULL){
            if(root->right == NULL){
              root->right = invertTree(root->left);
              root->left = NULL;
            }
            else if(root->left == NULL){
              root->left = invertTree(root->right);
              root->right = NULL;
            }
            else{
              root->left = invertTree(root->left);
              root->right = invertTree(root->right);
              swap(root->left, root->right);
            }
          }
        }
      return root;
    }
/*
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        if(root->right == NULL){
            root->right = root->left;
            root->left = NULL;
            invertTree(root->right);
        }
        else if(root->left == NULL){
            root->left = root->right;
            root->right = NULL;
            invertTree(root->left);
        }
        else{
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
            invertTree(root->right);
            invertTree(root->left);
        }
        return root;
    }
*/
};