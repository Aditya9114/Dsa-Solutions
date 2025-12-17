class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;
        for(int i=0;i<n;){
            int jumpDis = nums[i];
            if(jumpDis ==0)return false;
            int j = i+1;
            int max = j;
            while(jumpDis > 0){
                if(j == n-1)return true;
                if(j + nums[j] >= max + nums[max]){
                    max = j;
                }
                j++;
                jumpDis--;
            }
            i = max;
            if(max + nums[max] >= (n-1))return true;   
        }
        return false;
    }
};