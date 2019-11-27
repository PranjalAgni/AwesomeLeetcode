class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int max_product_so_far = nums[0];
        int min_prod_curr = nums[0];
        int max_prod_curr = nums[0];
        int prev_max;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                max_prod_curr = max(max_prod_curr * nums[i], nums[i]);
                min_prod_curr = min(min_prod_curr * nums[i], nums[i]);
            } else {
                prev_max = max_prod_curr;
                max_prod_curr = max(min_prod_curr * nums[i], nums[i]);
                min_prod_curr = min(prev_max * nums[i], nums[i]);
            }

            max_product_so_far = max(max_product_so_far, max_prod_curr);
        }

        return max_product_so_far;
    }
};
