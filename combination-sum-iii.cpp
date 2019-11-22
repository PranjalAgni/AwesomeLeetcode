class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        findCombination(ans, curr, 1, k, n);
        return ans;
    }

    void findCombination(vector<vector<int>>& ans, vector<int>& curr, int start, int k, int n) {
        if (n < 0) {
            return;
        }

        if (n == 0) {
            if (curr.size() == k) ans.push_back(curr);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (n - i >= 0) {
                curr.push_back(i);
                findCombination(ans, curr, i + 1, k, n - i);
                curr.pop_back();
            }
        }
    }
};