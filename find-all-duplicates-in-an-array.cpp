// class Solution {
//    public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int len = nums.size();
//         if (len == 0) return {};
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         for (int i = 1; i < len; i++) {
//             if (nums[i] == nums[i - 1]) ans.push_back(nums[i]);
//         }

//         return ans;
//     }
// };

// class Solution {
//    public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         int len = nums.size();
//         if (len == 0) return {};
//         vector<int> freq(len + 1);

//         for (int i = 0; i < len; i++) {
//             freq[nums[i]] += 1;
//         }

//         vector<int> ans;
//         for (int i = 1; i <= len; i++) {
//             if (freq[i] == 2) ans.push_back(i);
//         }

//         return ans;
//     }
// };

class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};

        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            } else {
                ans.push_back(abs(nums[i]));
            }
        }

        return ans;
    }
};