class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();

        if (size < 2) return false;

        vector<int> preSum(size);

        preSum[0] = nums[0];

        for (int i = 1; i < size; i++) {
            preSum[i] = nums[i] + preSum[i - 1];
        }

        unordered_map<int, int> pos;
        pos[0] = -1;
        k = abs(k);
        for (int i = 0; i < size; i++) {
            int res = preSum[i];

            if (k != 0) {
                res = preSum[i] % k;
            }

            if ((pos.find(res) != pos.end()) && ((i - pos[res]) > 1)) {
                return true;
            }

            if (pos.find(res) == pos.end()) pos[res] = i;
        }

        return false;
    }
};

// 23 2 4 6 7
//k = 6
// 23 25 29 35 42
//curr = 23,25,29
//res = 5
// [0:-1, 5: 0, 1: 1, ]