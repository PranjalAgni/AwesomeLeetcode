class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 1; i < cols; i++) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < rows; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[rows - 1][cols - 1];
    }
};

/**
 * 2 2 3
 * 4 5 6 
 * 7 8 0
 * 1 5 1
 * 
 * 2 4 7
 * 6 5 6
 * 13 8 0
 * 14 5 1
 * 
 * 
 * New Matrix
 * [1,3,1],
  [1,5,1],
  [4,2,1]
 * 
 * 1 4 5
 * 2 5 1
 * 6 2 1
 * 
 * 1 4 5
 * 2 7 6
 * 6 8 7
 * 
 * 
**/