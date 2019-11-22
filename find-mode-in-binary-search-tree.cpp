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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> result;
        vector<int> nodes;
        int freq = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < treeList.size(); i++) {
            map[treeList[i]] += 1;

            if (map[treeList[i]] > freq) {
                freq = map[treeList[i]];
            }

            if (map[treeList[i]] == 1) {
                nodes.push_back(treeList[i]);
            }
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (map[nodes[i]] == freq) {
                result.push_back(nodes[i]);
            }
        }

        return result;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        treeList.push_back(root->val);
        inorder(root->right);
    }
};