class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        /** 
         * Idea is to store each set od diagonals as list 
         * Then reverse the even ones diagonal
         * Fun fact: in a matrix elements whose indexes i.e(i,j)
         * sum is equal are diagonal to each other.
        **/
        vector<int> nums;
        int rows = matrix.size();
        if (rows == 0) return nums;
        int cols = matrix[0].size();

        vector<vector<int>> dig(cols + rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int ind = i + j;
                dig[ind].push_back(matrix[i][j]);
            }
        }

        for (int i = 0; i < dig.size(); i++) {
            if (i % 2 == 0 && dig[i].size() > 1) {
                reverse(dig[i].begin(), dig[i].end());
            }
            for (int j = 0; j < dig[i].size(); j++) {
                nums.push_back(dig[i][j]);
            }
        }
        return nums;
    }
};