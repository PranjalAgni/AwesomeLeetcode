class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        int start = 0;
        int end = nums.size() - 1;
        int pre = 1;

        while (start <= end) {
            ans[start] = pre;
            pre *= nums[start];
            start += 1;
        }

        int post = 1;
        while (end >= 0) {
            ans[end] *= post;
            post *= nums[end];
            end -= 1;
        }

        return ans;
    }
};
