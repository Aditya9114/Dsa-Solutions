class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>leftSum(nums.size(),0);
        vector<int>rightSum(nums.size(),0);
        int sum = 0;
        for(int i=1;i<nums.size();i++){
            sum = sum + nums[i-1];
            leftSum[i] = sum;
        }
        sum = 0;
        for(int i=nums.size()-2; i>=0; i--){
            sum = sum + nums[i+1];
            rightSum[i] = sum;
        }
        vector<int> ans(nums.size(), 0);
        for(int i=0;i <nums.size();i++){
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};