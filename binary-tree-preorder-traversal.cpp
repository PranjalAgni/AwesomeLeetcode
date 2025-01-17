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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        findPreorderTraversal(root, ans);
        return ans;
    }

    void findPreorderTraversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        ans.push_back(root->val);
        findPreorderTraversal(root->left, ans);
        findPreorderTraversal(root->right, ans);
    }
};