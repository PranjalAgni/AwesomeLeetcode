class Solution {
   public:
    bool isAlpha(char ch) {
        if ((ch >= 'a' && ch <= 'z') || ch >= 'A' && ch <= 'Z') return true;
        return false;
    }

    string reverseOnlyLetters(string S) {
        int start = 0;
        int end = S.length() - 1;
        while (start < end) {
            while (start < end && !isAlpha(S[start])) {
                start += 1;
            }

            while (start < end && !isAlpha(S[end])) {
                end -= 1;
            }

            char temp = S[start];
            S[start] = S[end];
            S[end] = temp;

            start += 1;
            end -= 1;
        }

        return S;
    }
};