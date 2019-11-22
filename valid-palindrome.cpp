class Solution {
   public:
    bool isPalindrome(string s) {
        int size = s.length();

        if (size == 0) return true;
        int start = 0;
        int end = size - 1;
        bool charMet = false;
        while (start < end) {
            while (isalnum(s[start]) == false && start < end) {
                start++;
            }

            while (isalnum(s[end]) == false && start < end) {
                end--;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};