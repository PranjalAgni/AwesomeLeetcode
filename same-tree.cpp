/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = 0;
       if (p && q && p->val == q->val) {
           
           if (p->left && q->left) {
               ans = isSameTree(p->left, q->left);
           } else {
               return false;
           }

           if (p->right && q->right) {
               ans = isSameTree(p->right, q->right);
           } else {
               return false;
           }

           return true;
       } else {
           return false;
       }
    }
};



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (p == NULL && q == NULL) {
          return 1;
      }

      if (p != NULL &&  q != NULL) {
          return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
      }

      return 0;
    }   
};
