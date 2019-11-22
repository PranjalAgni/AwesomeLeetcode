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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n == 0)
            return ans;

        ans = constructTrees(1, n);

        return ans;
    }

    vector<TreeNode*> constructTrees(int start, int end) {
        vector<TreeNode*> treeList;

        if (start > end) {
            treeList.push_back(NULL);
            return treeList;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftList = constructTrees(start, i - 1);
            vector<TreeNode*> rightList = constructTrees(i + 1, end);

            for (int j = 0; j < leftList.size(); j++) {
                TreeNode* leftNode = leftList[j];
                for (int k = 0; k < rightList.size(); k++) {
                    TreeNode* rightNode = rightList[k];

                    TreeNode* node = new TreeNode(i);
                    node->left = leftNode;
                    node->right = rightNode;

                    treeList.push_back(node);
                }
            }
        }

        return treeList;
    }
};