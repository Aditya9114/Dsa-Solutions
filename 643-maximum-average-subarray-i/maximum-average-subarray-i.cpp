class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() == 1 && k == 1)return nums[0];
        int left = 0, right = 0;
        double sum = 0;
        double maxAvg = INT_MIN;
        while(right < nums.size()){
            sum += nums[right];
            if((right - left + 1) == k){
                if(maxAvg < (sum/k))maxAvg = sum/k;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxAvg;
    }
};