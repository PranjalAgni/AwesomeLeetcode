class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        findNumber(candidates, target, ans, curr, 0);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }

    void findNumber(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int idx) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i == idx || candidates[i - 1] != candidates[i]) {
                curr.push_back(candidates[i]);
                findNumber(candidates, target - candidates[i], ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
};