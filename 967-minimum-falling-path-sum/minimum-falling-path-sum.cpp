class Solution {
public:
    int f(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (j < 0 || j >= matrix[0].size()) {
            return 1e9;
        }
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int up = matrix[i][j] + f(matrix, i - 1, j, dp);
        int lDiagonal = matrix[i][j] + f(matrix, i - 1, j - 1, dp);
        int rDiagonal = matrix[i][j] + f(matrix, i - 1, j + 1, dp);

        return dp[i][j] = min(up, min(lDiagonal, rDiagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {

                int up = dp[i - 1][j];

                int lDiagonal = INT_MAX;
                int rDiagonal = INT_MAX;

                if (j > 0)
                    lDiagonal = dp[i - 1][j - 1];

                if (j < matrix[0].size() - 1)
                    rDiagonal = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min(up, min(lDiagonal, rDiagonal));
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};