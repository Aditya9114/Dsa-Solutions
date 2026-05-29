class Solution {
public:
    int minElement(vector<int>& nums) {
        int num;
        int min = INT_MAX;
        for(int i=0;i<nums.size();i++){
            num = nums[i];
            int sum = 0;
            while(num){ 
                int d = num % 10;
                sum += d;
                num = num / 10;
            }
            if(min > sum) min = sum;
        }
        return min;
    }
};