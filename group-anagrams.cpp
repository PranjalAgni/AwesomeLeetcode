class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // [x]for word in list:
        // [x]if visited continue
        // [x]set current_word
        // [x]instantiate a list insert current_word
        // [x]mark visited
        // find its freq O(n)
        // iterate in all next to current_word
        // if visited continue
        // mark visited
        // if length is same compute its freq
        // check if freq matches
        // else discard it
        // if its anagram insert it in list
        vector<vector<string>> ans;
        vector<int> visited(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            if (visited[i] == 1) continue;
            string current_word = strs[i];
            vector<string> currentList;
            currentList.push_back(current_word);
            visited[i] = 1;
            vector<int> freq(27);
            for (int f = 0; f < current_word.length(); f++) {
                freq[current_word[f] & 31] += 1;
            }

            for (int j = i + 1; j < strs.size(); j++) {
                if (visited[j] == 1) continue;
                visited[j] = 1;
                bool isAnagram = false;
                if (strs[j].length() == current_word.length()) {
                    vector<int> t_freq(27);
                    for (int f = 0; f < strs[j].length(); f++) {
                        t_freq[strs[j][f] & 31] += 1;
                    }

                    for (int idx = 1; idx < 27; idx++) {
                        isAnagram = true;
                        if (freq[idx] != t_freq[idx]) {
                            isAnagram = false;
                            break;
                        }
                    }
                } else {
                    break;
                }

                if (isAnagram) {
                    currentList.push_back(strs[j]);
                } else {
                    visited[j] = 0;
                }
            }

            ans.push_back(currentList);
        }

        return ans;
    }
};