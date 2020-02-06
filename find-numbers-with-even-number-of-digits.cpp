class Solution {
   public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (curr < 0) curr *= -1;
            int digs = floor(log10(curr) + 1);
            if ((digs & 1) == 0) ans += 1;
        }
        return ans;
    }
};