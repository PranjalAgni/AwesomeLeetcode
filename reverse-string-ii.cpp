class Solution {
   public:
    void reverseCustom(string& str, int start, int end) {
        end -= 1;
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start += 1;
            end -= 1;
        }
    };

    string reverseStr(string s, int k) {
        int len = s.length();
        for (int itr = 0; itr < len;) {
            int tempLen = len - itr;
            if (2 * k <= tempLen) {
                reverseCustom(s, itr, itr + k);
                itr += (2 * k);
            } else if (2 * k > tempLen && k <= tempLen) {
                reverseCustom(s, itr, itr + k);
                itr += tempLen;
            } else {
                reverseCustom(s, itr, len);
                itr = len;
            }
        }
        return s;
    }
};