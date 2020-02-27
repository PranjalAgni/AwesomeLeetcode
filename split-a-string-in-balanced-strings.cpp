class Solution {
   public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int normalize = 0;
        for (char ch : s) {
            if (ch == 'R') {
                normalize += 1;
            } else {
                normalize -= 1;
            }

            if (normalize == 0) ans += 1;
        }

        return ans;
    }
};