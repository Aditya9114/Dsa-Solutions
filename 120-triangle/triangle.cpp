class Solution {
public:
    int f(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
        if(i > triangle.size()-1 || j > triangle[i].size()-1){
            return 0;
        }
        if(dp[i][j] != INT_MAX)return dp[i][j];
        int leftCall = f(triangle, i+1,j,dp);
        int rightCall = f(triangle, i+1,j+1,dp);
        return dp[i][j] = min(leftCall,rightCall) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        return f(triangle,0,0,dp);
    }
};