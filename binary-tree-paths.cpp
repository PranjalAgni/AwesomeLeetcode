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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string current = "";
        findRootToLeaf(root, ans, current);
        return ans;
    }

    void findRootToLeaf(TreeNode* root, vector<string>& ans, string current) {
        if (root == NULL) {
            return;
        }
        bool leaf = true;
        int value = root->val;

        if (root->left || root->right) {
            leaf = false;
            current += to_string(value) + "->";
        }
        if (leaf) {
            current += to_string(value);
            ans.push_back(current);
            current = "";
            leaf = true;
        }

        else {
            findRootToLeaf(root->left, ans, current);
            findRootToLeaf(root->right, ans, current);
        }
    }
};