class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    if ((sum - target) < diff) {
                        diff = sum - target;
                        res = min(res, (sum));
                    }
                    high--;
                } else {
                    if ((target - sum) < diff) {
                        diff = target - sum;
                        res = min(res, (sum));
                    }
                    low++;
                }
            }
        }
        return res;
    }
};