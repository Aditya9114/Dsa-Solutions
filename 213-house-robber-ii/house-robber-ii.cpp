class Solution {
public:
    int fun(vector<int> &nums, int ind, vector<vector<int>> &dp, int lastVisited) {
        
        if(ind < 0)
            return 0;

        if(ind == 0) {
            if(lastVisited == 1)
                return 0;
            return nums[0];
        }

        if(dp[ind][lastVisited] != -1)
            return dp[ind][lastVisited];

        int newLastVisited = lastVisited;

        if(ind == nums.size() - 1)
            newLastVisited = 1;

        int take = nums[ind] + fun(nums, ind - 2, dp, newLastVisited);

        int notTake = fun(nums, ind - 1, dp, lastVisited);

        return dp[ind][lastVisited] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return fun(nums, n - 1, dp, 0);
    }
};