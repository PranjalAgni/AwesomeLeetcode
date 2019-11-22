class Solution {
   public:
    string addStrings(string num1, string num2) {
        int size1 = num1.length();
        int size2 = num2.length();
        string result;
        if (size1 < size2) {
            result = solve(num1, num2);
        } else {
            result = solve(num2, num1);
        }
        return result;
    }

    string solve(string a, string b) {
        string result = "";

        // 2354
        //  721
        //  0 75
        int carry = 0;
        int j = b.length() - 1;
        for (int i = a.length() - 1; i >= 0; i--, j--) {
            int num_a = a[i] - '0';
            int num_b = b[j] - '0';
            int c = carry + num_a + num_b;
            if (c > 9) {
                int temp = c % 10;
                c = c / 10;
                carry = c % 10;
                result = to_string(temp) + result;
            } else {
                result = to_string(c) + result;
                carry = 0;
            }
        }

        for (; j >= 0; j--) {
            int num_b = b[j] - '0';
            int c = carry + num_b;
            if (c > 9) {
                int temp = c % 10;
                c = c / 10;
                carry = c % 10;
                result = to_string(temp) + result;
            } else {
                result = to_string(c) + result;
                carry = 0;
            }
        }

        if (carry != 0) result = to_string(carry) + result;
        return result;
    }
};
