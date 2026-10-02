class Solution {
public:
    int f(int ind, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(ind == 0 && amount < coins[0])return 1e8;
        if(ind < 0)return 1e8;
        if(dp[ind][amount]!= -1)return dp[ind][amount];
        int take = 1e8;
        if(coins[ind] <= amount){
            take = 1 + f(ind,amount-coins[ind],coins,dp);
        }
        int notTake = f(ind-1,amount,coins,dp);
        return dp[ind][amount] = min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1, -1));
        int ans = f(coins.size()-1, amount, coins,dp);
        if(ans == 1e8)return -1;
        return ans;
    }
};