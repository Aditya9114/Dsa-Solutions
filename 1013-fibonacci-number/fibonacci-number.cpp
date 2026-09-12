class Solution {
public:
    int f(vector<int> &dp, int n){
        if(n<=1)return n;
        if(dp[n]!= -1)return dp[n];
        dp[n] = f(dp,n-1) + f(dp,n-2);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = f(dp,n);
        return ans;
    }
};