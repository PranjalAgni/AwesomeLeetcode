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
    void findPathSum(TreeNode* root, vector<vector<int>>& paths, vector<int> path, int sum) {
        if (root == NULL) {
            return;
        }

        sum -= root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                paths.push_back(path);
            }

            path = vector<int>();
        } else {
            findPathSum(root->left, paths, path, sum);
            findPathSum(root->right, paths, path, sum);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;

        findPathSum(root, paths, path, sum);
        return paths;
    }
};