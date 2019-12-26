class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        if (len == 0) return ans;

        for (int i = 0; i < len; i++) {
            nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }

        return ans;
    }
};

// class Solution {
//    public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         int len = nums.size();
//         if (len == 0) return ans;
//         sort(nums.begin(), nums.end());
//         vector<int> seen(len + 1);
//         for (int i = 0; i < len; i++) {
//             seen[nums[i]] = 1;
//         }

//         for (int i = 1; i <= len; i++) {
//             if (seen[i]) ans.push_back(i);
//         }

//         return ans;
//     }
// };