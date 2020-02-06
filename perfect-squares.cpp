class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            // cout << "Calculating: "
            //      << "dp[" << i << "]" << endl;
            for (int j = 1; j * j <= i; j++) {
                // cout << j * j << endl;
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

/**
 int ans = INT_MAX;
        int now = 0;
        while (start <= end) {
            int curr = psquares[start] + psquares[end];

            if (psquares[start] == n || psquares[end] == n) {
                now = 1;
                break;
            }

            if (curr == n) {
                now = 2;
                break;
            } else if (curr < n) {
                int diff = n - curr;

                if (diff % psquares[start] == 0) {
                    now = 2 + (diff / psquares[start]);
                }

                int temp = now;
                if (diff % psquares[end] == 0) {
                    now = 2 + (diff / psquares[end]);
                }

                now = min(now, temp);
                start += 1;
            } else {
                end -= 1;
            }

            ans = min(now, ans);
            now = INT_MAX;
        }
**/