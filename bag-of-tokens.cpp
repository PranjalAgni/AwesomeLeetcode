class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());

        int len = tokens.size();
        int start = 0;
        int end = len - 1;
        int coins = 0;

        while (start < end) {
            bool isMoving = false;
            if (P >= tokens[start]) {
                P -= tokens[start];
                coins += 1;
                start += 1;
                isMoving = true;
            } else if (coins > 0) {
                P += tokens[end];
                coins -= 1;
                end -= 1;
                isMoving = true;
            }

            if (!isMoving) break;
        }

        if (P >= tokens[start]) coins += 1;

        return coins;
    }
};
