class Solution {
   public:
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            string root = arr[i];
            bool isUnique = isUniqueChars(root);
            if (!isUnique) continue;
            int res = root.length();
            for (int j = 0; j < arr.size(); j++) {
                if (j == i) continue;
                string current = arr[j];
                isUnique = isUniqueChars(root + current);
                if (isUnique) {
                    root += current;
                    res += current.length();
                }
            }

            if (res > ans) ans = res;
        }

        return ans;
    }

    bool isUniqueChars(string str) {
        unordered_map<char, int> unique;

        for (char ch : str) {
            if (unique[ch] == 1) {
                return false;
            }
            unique[ch] += 1;
        }

        return true;
    }
};

/**
 * ["a", "abc", "d", "de", "def"]
 * 
 * a -> abc [!]
 * a ->> d 2
 * a ->> de 3
 * a ->> def 4 [x]
 * abc ->>  d
 * abc ->> 
 *
 **/