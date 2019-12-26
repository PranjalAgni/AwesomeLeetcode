class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> curr;
        int len = nums.size();

        if (len < 4) return ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 3; i++) {
            for (int j = i + 1; j < len - 2; j++) {
                int low = j + 1;
                int high = len - 1;

                while (low < high) {
                    int sum = nums[i] + nums[j] + nums[low] + nums[high];

                    if (sum == target) {
                        curr.insert({nums[i], nums[j], nums[low], nums[high]});
                    }
                    if (sum <= target) {
                        low += 1;
                    }
                    if (sum >= target) {
                        high -= 1;
                    }
                }
            }
        }

        for (auto elt : curr) {
            ans.push_back(elt);
        }

        return ans;
    }
};