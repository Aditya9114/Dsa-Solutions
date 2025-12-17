class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;

        int maxIndex = 0;
        for(int i=0;i<n-1;i++){
            if(maxIndex < i)return false;
            if(maxIndex < nums[i]+i){
                maxIndex = nums[i]+i;
            }
            if(maxIndex >= n-1)return true;
        }
        return false;
    }
};