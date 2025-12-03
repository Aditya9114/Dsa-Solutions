class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 1;
        int len = nums.size();
        int high = len-2;
        if(len==1 || nums[0]>nums[1])return 0;
        if(nums[len-1] > nums[high])return len-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;
            if(nums[mid]<nums[mid-1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return 0;
    }
};