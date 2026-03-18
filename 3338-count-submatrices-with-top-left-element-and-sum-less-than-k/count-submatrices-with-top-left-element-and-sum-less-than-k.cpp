class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pre(m, vector<int>(n, 0));

        int count = 0;
        int sum = 0;

        // for column (first row)
        for (int i = 0; i < n; i++) {
            sum += grid[0][i];
            if (sum <= k) count++;
            else break;
        }

        // for row (first column, skip [0][0] already counted)
        sum = grid[0][0];
        for (int i = 1; i < m; i++) {
            sum += grid[i][0];
            if (sum <= k) count++;
            else break;
        }

        // for interior cells (i>=1, j>=1)
        // build prefix sums and check each cell
        // pre[i][j] = sum of submatrix (0,0) to (i,j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i][j] = grid[i][j];
                if (i > 0) pre[i][j] += pre[i-1][j];
                if (j > 0) pre[i][j] += pre[i][j-1];
                if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];

                // only count interior; first row/col already counted
                if (i >= 1 && j >= 1 && pre[i][j] <= k) count++;
            }
        }

        return count;
    }
};