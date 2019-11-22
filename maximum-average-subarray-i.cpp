class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg_so_far = INT_MIN;
        double current_sum = 0;
        int limit = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            limit += 1;

            if (limit == k) {
                double current_avg = current_sum / k;
                max_avg_so_far = max(current_avg, max_avg_so_far);
                current_sum -= nums[i + 1 - k];
                limit -= 1;
            }
        }

        return max_avg_so_far;
    }
};
// 1 2 3 4
// 10
//