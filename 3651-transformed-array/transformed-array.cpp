class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size,0);
        for(int i=0;i<size;i++){
            if(nums[i]==0){
                ans[i] = nums[i];
            }
            if(nums[i] > 0){
                int index = (nums[i] + i) % size;
                ans[i] = nums[index];
            }
            else{
                int num = abs(nums[i]) % size;
                int index = (size - num + i) % size;
                ans[i] = nums[index];
            }
        }
        return ans;
    }
};