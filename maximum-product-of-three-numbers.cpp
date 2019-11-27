class Solution {
   public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;

        int size = nums.size();
        int a = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int b = nums[0] * nums[1] * nums[size - 1];
        return max(a, b);
    }
};

// [-10,-10,2,4,5,15]
//