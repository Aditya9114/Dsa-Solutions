class Solution {
public:
    int findSumRecursive(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        if(row==0 && col==0)return grid[0][0];
        if(row < 0 || col<0)return INT_MAX;
        if(dp[row][col] != -1)return dp[row][col];
        int up = findSumRecursive(grid,row-1,col,dp);
        int left = findSumRecursive(grid,row,col-1,dp);
        return dp[row][col] = min(left,up)+ grid[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        dp[0][0] = grid[0][0];
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                int right=INT_MAX,down=INT_MAX;
                if(j==0 && i==0)continue;
                if(i>0){
                    down = dp[i-1][j];
                }
                if(j>0){
                    right = dp[i][j-1];
                }
                dp[i][j] = min(right,down) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};