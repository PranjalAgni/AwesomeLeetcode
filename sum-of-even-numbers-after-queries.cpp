class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int len = A.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if ((A[i] & 1) == 0) sum += A[i];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0];
            int pos = queries[i][1];
            bool beforeStatus = ((A[pos] & 1) == 0);
            A[pos] += val;
            bool afterStatus = ((A[pos] & 1) == 0);
            if (beforeStatus == false && afterStatus == true) {
                sum += A[pos];
            } else if (beforeStatus == true && afterStatus == true) {
                sum += val;
            } else if (beforeStatus == true && afterStatus == false) {
                sum -= (A[pos] - val);
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
