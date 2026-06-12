class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pre = 1,preMax = INT_MIN;
        int suff = 1, suffMax = INT_MIN;
        for(int i=0; i<nums.size();i++){
            pre *= nums[i];
            if(preMax < pre)preMax = pre;
            if(pre == 0)pre = 1;
        }
        for(int i=nums.size()-1; i>=0; i--){
            suff *= nums[i];
            if(suffMax < suff) suffMax = suff;
            if(suff == 0)suff = 1;
        }
        ans = max(preMax,suffMax);
        return ans;
    }
};