class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        int suffixProduct = 1, prefixProduct = 1;
        for(int i=1; i<nums.size();i++){
            prefixProduct *= nums[i-1];
            prefix[i] = prefixProduct;
        }
        for(int i=nums.size()-2; i>=0; i--){
            suffixProduct *= nums[i+1];
            suffix[i] = suffixProduct;
        }
        vector<int> ans;
        for(int i=0; i<nums.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};