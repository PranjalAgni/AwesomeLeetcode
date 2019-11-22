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
    vector<int> treeList;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int min = INT_MAX;
        for (int i = 1; i < treeList.size(); i++) {
            if ((treeList[i] - treeList[i - 1]) < min) {
                min = treeList[i] - treeList[i - 1];
            }
        }

        return min;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        treeList.push_back(root->val);
        inorder(root->right);
    }
};