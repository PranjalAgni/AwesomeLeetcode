class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] += 1;
        }

        int res = 0;
        vector<pair<int, int>> used;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            map[first] -= 1;
            int second = nums[i] + k;

            pair<int, int> current(first, second);
            if (count(used.begin(), used.end(), current) || map[second] < 1) {
                map[first] += 1;
                continue;
            }

            used.push_back(make_pair(first, second));
            res += 1;
            map[first] += 1;
        }

        return res;
    }
};