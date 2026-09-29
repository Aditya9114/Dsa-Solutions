class Solution {
public:
    bool f(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (index == 0) {
            return nums[0] == target;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        bool notTake = f(index - 1, target, nums, dp);
        bool take = false;
        if (target >= nums[index]) {
            take = f(index - 1, target - nums[index], nums, dp);
        }
        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, -1));
        return f(nums.size() - 1, sum / 2, nums, dp);
    }
};