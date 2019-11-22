class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) return 0;

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                if (nums[i] > nums[i + 1]) {
                    return i;
                }
            } else if (i == size - 1) {
                if (nums[i] > nums[i - 1]) {
                    return i;
                }
            } else {
                if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
                    return i;
                }
            }
        }

        return 0;
    }
};