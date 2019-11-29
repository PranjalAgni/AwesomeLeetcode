class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int start = 0;
        int end = 0;
        int pro = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            pro *= nums[i];
            end = i;
            if (pro >= k) {
                while (pro >= k && start <= end) {
                    pro /= nums[start];
                    start += 1;
                }
            }
            ans += end - start + 1;
        }
        return ans;
    }
};
