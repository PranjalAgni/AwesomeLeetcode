class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& A) {
        // return max idx

        int max = A[0];
        int idx = 0;
        for (int i = idx; i < A.size(); i++) {
            if (A[i] > max) {
                max = A[i];
                idx = i;
            }
        }
        return idx;
    }
};