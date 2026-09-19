class Solution {
public:
    int find(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x>n || y>m){
            return 0;
        }
        if(dp[x][y]!= -1)return dp[x][y];
        if(x==n && y==m){
            return 1;
        }
        int left = find(x+1,y,m,n,dp);
        int right = find(x,y+1,m,n,dp);
        return dp[x][y] = left + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(1,1,m,n,dp);
    }
};