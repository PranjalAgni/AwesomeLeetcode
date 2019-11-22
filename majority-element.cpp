class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> lookup;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            lookup[nums[i]] += 1;
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        int num = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (lookup[nums[i]] > ans) {
                ans = lookup[nums[i]];
                num = nums[i];
            }
        }

        return num;
    }
};