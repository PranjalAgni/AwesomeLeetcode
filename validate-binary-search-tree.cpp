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
    bool isValidBST(TreeNode* root) {
        return checkValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool checkValidBST(TreeNode* root, long low, long high) {
        if (root == NULL) {
            return true;
        }

        if (root->val < low || root->val > high) return false;

        return checkValidBST(root->left, low, root->val) && checkValidBST(root->right, root->val, high);
    }
};

class Solution {
   public:
    vector<int> treeList;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for (int i = 1; i < treeList.size(); i++) {
            if (treeList[i] <= treeList[i - 1]) {
                return false;
            }
        }

        return true;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        treeList.push_back(root->val);
        inorder(root->right);
    }
};