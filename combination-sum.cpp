class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        findNumbers(candidates, target, ans, curr, 0);

        return ans;
    }

    void findNumbers(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& current, int idx) {
        if (target < 0) {
            target = 0;
        }

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                current.push_back(candidates[i]);
                findNumbers(candidates, target - candidates[i], ans, current, i);
                current.pop_back();
            }
        }
    }
};