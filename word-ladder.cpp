class Solution {
   public:
    bool stringDifference(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) count++;
            if (count > 1) return false;
        }
        return (count == 1) ? true : false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> graph;
        graph.push(make_pair(beginWord, 1));
        vector<bool> visited(wordList.size());
        while (!graph.empty()) {
            string word = graph.front().first;
            int len = graph.front().second;
            int ans = len;
            graph.pop();

            for (int i = 0; i < wordList.size(); i++) {
                if (visited[i]) continue;
                string currWord = wordList[i];

                if (stringDifference(currWord, word)) {
                    visited[i] = true;
                    int ans = len + 1;
                    graph.push(make_pair(currWord, ans));
                    if (currWord == endWord) {
                        return ans;
                    }
                }
            }
        }
        return 0;
    }
};