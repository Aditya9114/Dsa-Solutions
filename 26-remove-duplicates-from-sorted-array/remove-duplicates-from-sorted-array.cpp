class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1,p2;
        p1 = 0;
        p2 = 1;
        int k = 1;
        while(p2 < nums.size()){
            if(nums[p2] == nums[p1])p2++;
            else{
                p1++;
                nums[p1] = nums[p2];
                p2++;
                k++;
            }
        }
        return k;
    }
};