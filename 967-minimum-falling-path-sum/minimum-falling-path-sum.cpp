class Solution {
public:
    int f(vector<vector<int>> &matrix, int i, int j,vector<vector<int>> &dp){
        if(j<0 || j>=matrix[0].size()){
            return 1e9;
        }
        if(i==0)return matrix[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int up = matrix[i][j] + f(matrix,i-1,j,dp);
        int lDiagonal = matrix[i][j] + f(matrix,i-1,j-1,dp);
        int rDiagonal = matrix[i][j] + f(matrix,i-1,j+1,dp);

        return dp[i][j] = min(up,min(lDiagonal,rDiagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int min1 = INT_MAX;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        for(int j=0; j<matrix[0].size(); j++){
            int min2 = f(matrix,matrix.size()-1,j,dp);
            min1 = min(min1,min2);
        }
        return min1;
    }
};