class Solution {
   public:
    int consecutiveNumbersSum(int N) {
        int limit = sqrt(2 * N);
        int count = 1;

        for (int num = 2; num <= limit; num++) {
            if ((N - (num * (num + 1) / 2)) % num == 0) {
                count += 1;
            }
        }

        // for (int num = 1; num <= end; num++) {
        //     if (curr_sum < N) {
        //         curr_sum += num;
        //     }

        //     while (curr_sum > N && start <= num) {
        //         curr_sum -= start;
        //         start += 1;
        //     }

        //     if (curr_sum > N) {
        //         break;
        //     }

        //     if (curr_sum == N) {
        //         curr_sum -= start;
        //         start += 1;
        //         poss += 1;
        //     }
        // }

        return poss;
    }
};