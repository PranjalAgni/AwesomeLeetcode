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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int lDep = maxDepth(root->left);
            int rDep = maxDepth(root->right);
            return 1 + max(lDep,rDep);
        }
    }
};