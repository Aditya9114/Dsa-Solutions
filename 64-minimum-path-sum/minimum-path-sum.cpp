class Solution {
public:
    int findSum(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        if(row==0 && col==0)return grid[0][0];
        if(row < 0 || col<0)return INT_MAX;
        if(dp[row][col] != -1)return dp[row][col];
        int up = findSum(grid,row-1,col,dp);
        int left = findSum(grid,row,col-1,dp);
        return dp[row][col] = min(left,up)+ grid[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
       return findSum(grid,grid.size()-1, grid[0].size()-1, dp); 
    }
};