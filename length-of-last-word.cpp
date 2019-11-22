class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool go = true;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (go) continue;
                break;
            }
            len += 1;
            go = false;
        }
        return len;
    }
};