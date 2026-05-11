class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int product = nums[i];
            ans = max(ans,product);
            for(int j=i+1;j<nums.size();j++){
                product = product * nums[j];
                ans = max(ans,product);
            }
        }
        return ans;
    }
};