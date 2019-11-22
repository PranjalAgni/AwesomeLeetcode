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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverseTree(root, ans);
        return ans;
    }

    void traverseTree(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        traverseTree(root->left, ans);
        traverseTree(root->right, ans);
        ans.push_back(root->val);
    }
};