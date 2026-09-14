class Solution {
public:
    int maxSum(vector<int> &nums, int maxi, int index, vector<int> &dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index]!= -1)return dp[index];
        int left = maxSum(nums,maxi,index+2,dp);
        int right = maxSum(nums,maxi,index+3,dp);
        maxi = max(left+nums[index],right+nums[index]);
        dp[index] = maxi;
        return maxi;
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int a = maxSum(nums,0,0,dp);
        int b = maxSum(nums,0,1,dp);
        return max(a,b);
    }
};