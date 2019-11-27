class Solution {
   public:
    int calPoints(vector<string>& ops) {
        vector<int> sequence(ops.size());

        int pos = 0;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                pos -= 1;
            } else if (ops[i] == "D") {
                sequence[pos++] = 2 * sequence[pos - 1];
            } else if (ops[i] == "+") {
                sequence[pos++] = sequence[pos - 1] + sequence[pos - 2];

            } else {
                sequence[pos++] = stoi(ops[i]);
            }
        }

        int res = 0;
        for (int i = 0; i < pos; i++) {
            res += sequence[i];
            cout << sequence[i] << "  ";
        }

        return res;
    }
};
