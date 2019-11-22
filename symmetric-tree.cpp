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

    bool isMirror(TreeNode* rootA, TreeNode* rootB) {
        if (rootA == NULL && rootB == NULL) {
            return 1;
        }

        if (rootA != NULL && rootB != NULL) {
            return (rootA->val == rootB->val && isMirror(rootA->left, rootB->right) && isMirror(rootA->right, rootB->left));
        }
        return 0;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
