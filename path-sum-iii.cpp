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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }

        return findPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int findPathSum(TreeNode* root, int sum) {
        int count = 0;
        if (root == NULL) {
            return count;
        }

        if (sum == root->val) {
            count += 1;
        }
        count += findPathSum(root->left, (sum - root->val));
        count += findPathSum(root->right, (sum - root->val));

        return count;
    }
};