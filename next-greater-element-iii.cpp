class Solution {
   public:
    vector<string> numList;
    int nextGreaterElement(int n) {
        string num = to_string(n);
        permute(num, 0, num.length() - 1);
        unsigned int ans = INT_MAX;
        int result = -1;
        for (int i = 0; i < numList.size(); i++) {
            string curr = numList[i];
            unsigned int currVal = convertStrToInt(curr);
            unsigned int diff = currVal - n;
            if (diff > 0 && diff < ans) {
                ans = diff;
                result = currVal;
            }
        }
        return result;
    }

    void permute(string s, int l, int h) {
        if (l == h) {
            numList.push_back(s);
        } else {
            for (int i = l; i <= h; i++) {
                swap(s[l], s[i]);
                permute(s, l + 1, h);
                swap(s[l], s[i]);
            }
        }
    }

    unsigned int convertStrToInt(string num) {
        int size = num.length();
        //"253"
        // 0*10 + 2 = 2
        // 2*10 + 5 = 25
        // 25 * 10 + 3 = 253
        unsigned int val = 0;
        for (int i = 0; i < size; i++) {
            char curr = num[i];
            int currInt = curr - '0';
            val = val * 10 + currInt;
        }
        return val;
    }
};