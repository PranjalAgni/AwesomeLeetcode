class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> subSum;
        subSum.push_back(0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            subSum.push_back(sum);
        }

        int start = 0;
        int end = subSum.size() - 1;

        return computeSubarraySum(subSum, start, end, k);
    }

    bool computeSubarraySum(vector<int> subSum, int start, int end, int k) {
        if (start > end) return false;

        int diff = subSum[end] - subSum[start];

        if (isValid(diff, k)) return true;

        return (computeSubarraySum(subSum, start, end - 1, k) ||
                computeSubarraySum(subSum, start + 1, end, k) ||
                computeSubarraySum(subSum, start + 1, end - 1, k));
    }

    bool isValid(int diff, int k) {
        if (diff == k) return true;
        if (k == 0) return false;
        return (diff % k == 0);
    }
};