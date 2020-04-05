class Solution {
   public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prev;
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if ((i != arr.size() - 1) && prev != arr[i]) {
                if (cnt == prev)
                    return cnt;
                else {
                    cnt = 0;
                }
            }
            cnt += 1;
            prev = arr[i];
        }

        if (prev == cnt) return cnt;
        return -1;
    }
};