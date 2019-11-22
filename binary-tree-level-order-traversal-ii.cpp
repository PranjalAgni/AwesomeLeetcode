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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vect;
        if (root == NULL) return vect;
        stack<vector<int>> svect;
        vector<int> curr;
        queue<TreeNode *> qu;
        queue<TreeNode *> upcoming;
        qu.push(root);
       while(qu.empty() == false) {
           TreeNode* currNode = qu.front();
           qu.pop();
           curr.push_back(currNode->val);
           if (currNode->left) {
               upcoming.push(currNode->left);
           }

           if (currNode->right) {
               upcoming.push(currNode->right);
           }
           if (qu.empty() == true) {
                qu = upcoming;
                upcoming = queue<TreeNode *>();
                svect.push(curr);
                curr.clear(); 
           }
       }

       while(!svect.empty()) {
           vect.push_back(svect.top());
           svect.pop();
       }

       return vect; 
    }
};