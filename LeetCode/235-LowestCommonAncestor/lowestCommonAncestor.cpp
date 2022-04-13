// My solution to LeetCode 235 - Lowest Common Ancestory of a Binary Search Tree
// leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//
// Time - O(log(n)) - Faster than 93.66%
// Space - O(1) - Less than 92.63%
//
#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val) || root->val == p->val || root->val == q->val){
        return root;
      }
      if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left, p, q);
      }
      if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right, p, q);
      }
    }
};
main(){}