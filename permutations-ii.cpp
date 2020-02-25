class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        permuteVector(nums, len, ans);
        return ans;
    }

    void permuteVector(vector<int> nums, int len, vector<vector<int>>& ans) {
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                ans.push_back(nums);
                permuteVector(nums, len, ans);
                swap(nums[i], nums[i + 1]);
            }
        }

        return;
    }
};