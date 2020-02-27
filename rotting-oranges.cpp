class Solution {
   public:
    bool checkBoundary(pair<int, int> p, int rows, int cols) {
        if (p.first >= rows && p.second <= cols) return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int, int>> fresh;
        set<pair<int, int>> rotten;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    fresh.insert(make_pair(i, j));
                else if (grid[i][j] == 2)
                    rotten.insert(make_pair(i, j));
            }
        }

        vector<pair<int, int>> directions = {{0, -1},
                                             {0, 1},
                                             {-1, 0},
                                             {1, 0}};
        int minutes = 0;

        while (fresh.size() > 0) {
            set<pair<int, int>> infected;
            for (pair<int, int> pr : rotten) {
                for (pair<int, int> dir : directions) {
                    int nextI = pr.first + dir.first;
                    int nextJ = pr.second + dir.second;
                    pair<int, int> curr = make_pair(nextI, nextJ);
                    auto pos = fresh.find(curr);
                    if (pos != fresh.end()) {
                        fresh.erase(curr);
                        infected.insert(curr);
                    }
                }
            }

            if (infected.size() == 0) {
                return -1;
            }

            rotten = infected;

            minutes += 1;
        }

        return minutes;
    }
};

/*
    2 1 1 
    1 1 0
    0 1 1
*/

/*

        while (freshOranges > 0) {
            freshOranges -= 1;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 2) {
                        bool isMadeRotten = false;
                        pair<int, int> dir1(i - 1, j);
                        pair<int, int> dir2(i, j - 1);
                        pair<int, int> dir3(i + 1, j);
                        pair<int, int> dir4(i, j + 1);

                        if (checkBoundary(dir1, rows - 1, cols - 1) && grid[dir1.first][dir1.second] == 1) {
                            cout << "dir1: " << dir1.first << " " << dir1.second << endl;
                            freshOranges -= 1;
                            isMadeRotten = true;
                            grid[dir1.first][dir1.second] = 2;
                        }

                        if (checkBoundary(dir2, rows - 1, cols - 1) && grid[dir2.first][dir2.second] == 1) {
                            cout << "dir2: " << dir2.first << " " << dir2.second << endl;
                            freshOranges -= 1;
                            isMadeRotten = true;
                            grid[dir2.first][dir2.second] = 2;
                        }

                        if (checkBoundary(dir3, rows - 1, cols - 1) && grid[dir3.first][dir3.second] == 1) {
                            cout << "dir3: " << dir3.first << " " << dir3.second << endl;
                            freshOranges -= 1;
                            isMadeRotten = true;
                            grid[dir3.first][dir3.second] = 2;
                        }

                        if (checkBoundary(dir4, rows - 1, cols - 1) && grid[dir4.first][dir4.second] == 1) {
                            cout << "dir4: " << dir4.first << " " << dir4.second << endl;
                            freshOranges -= 1;
                            isMadeRotten = true;
                            grid[dir4.first][dir4.second] = 2;
                        }

                        if (isMadeRotten) timeElapsed += 1;
                    }
                }
            }
        }
*/