class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (map[sum - k] != 0) {
                result += map[sum - k];
            }

            map[sum] += 1;
        }
        return result;
    }
};