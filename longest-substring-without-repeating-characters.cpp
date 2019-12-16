class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int ans = 0;
        int curr = 0;
        int startLookupIdx = 0;
        bool status = true;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end() && (status || map[s[i]] >= startLookupIdx)) {
                ans = max(curr, ans);
                curr = i - map[s[i]];
                startLookupIdx = map[s[i]] + 1;
                status = false;

            } else {
                curr += 1;
            }
            map[s[i]] = i;
        }
        ans = max(curr, ans);

        return ans;
    }
};
