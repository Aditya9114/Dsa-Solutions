class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1=0,p2=1;
        int count = 0;
        if(nums.size() ==1)return;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
        }
        for(p1=0;p1<nums.size();p1++){
            if(nums[p1]==0){
                break;
            }
        }
        if(count == 0)return;
        p2 = p1+1;
        while(p2<nums.size()){
            if(nums[p2] != 0){
              nums[p1++] = nums[p2];    
            }
            p2++;
        }
        for(int i=nums.size()-1; count!=0; i--){
            nums[i] = 0;
            count--;
        }
    }
};