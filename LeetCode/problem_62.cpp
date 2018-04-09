// Unique Paths
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?



// Solution approach: dynamic approach
// in fact, C(m + n - 2, m - 1) when m > 1 and n > 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n + 1, 0);
        vector<vector<int> > res(m + 1, row);
        for(int i = 1; i <= m; i++) {
            res[i][1] = 1;
        }
        for(int j = 1; j <= n; j++) {
            res[1][j] = 1;
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[m][n];
    }
};
