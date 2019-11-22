class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        if (s == t) return s;
        unordered_map<char, int> str;
        unordered_map<char, int> pattern;

        // string
        for (int i = 0; i < s.length(); i++) {
            str[s[i]] += 1;
        }

        // pattern
        for (int i = 0; i < t.length(); i++) {
            pattern[t[i]] += 1;
        }

        string first = computeSubString(str, pattern, s, 1);
        string second = computeSubString(str, pattern, s, 2);

        if (first.length() < second.length()) return first;
        return second;
    }

    string computeSubString(unordered_map<char, int> str, unordered_map<char, int> pattern, string s, int option) {
        int start = 0;
        int end = s.length() - 1;

        if (option == 1) {
            while (start < end) {
                int startF = str[s[start]];
                int endF = str[s[end]];

                if (startF == 1 && endF == 1) break;
                if (startF > 1 && startF > endF) {
                    str[s[start]] -= 1;
                    start++;
                } else {
                    if (endF > 1) {
                        str[s[end]] -= 1;
                        end--;
                    }
                }
            }
        } else {
            while (start < end) {
                int startF = str[s[start]];
                int endF = str[s[end]];

                if (startF == 1 && endF == 1) break;
                if (endF > 1 && endF > startF) {
                    str[s[end]] -= 1;
                    end--;
                } else {
                    if (startF > 1) {
                        str[s[start]] -= 1;
                        start++;
                    }
                }
            }
        }

        while (start <= end) {
            int startF = pattern[s[start]];
            int endF = pattern[s[end]];
            if (startF != 0 && endF != 0) break;
            if (startF == 0) start++;
            if (endF == 0) end--;
        }

        return s.substr(start, end - start + 1);
    }
};
