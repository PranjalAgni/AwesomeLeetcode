class Solution {
   public:
    int numTeams(vector<int>& rating) {
        int teams = 0;
        if (rating.size() == 0) return teams;
        for (int i = 0; i < rating.size() - 2; ++i) {
            for (int j = i + 1; j < rating.size() - 1; ++j) {
                if (rating[j] > rating[i]) {
                    int high = rating.size() - 1;
                    while (j < high) {
                        if (rating[high] > rating[j]) {
                            teams += 1;
                        }
                        high -= 1;
                    }
                }
            }
        }

        for (int i = 0; i < rating.size() - 2; ++i) {
            for (int j = i + 1; j < rating.size() - 1; ++j) {
                if (rating[i] > rating[j]) {
                    int high = rating.size() - 1;
                    while (j < high) {
                        if (rating[high] < rating[j]) {
                            teams += 1;
                        }
                        high -= 1;
                    }
                }
            }
        }

        return teams;
    }
};