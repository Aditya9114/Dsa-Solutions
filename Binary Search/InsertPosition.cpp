class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans;
        int high=nums.size()-1;
        int low = 0;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        if(low == nums.size())return low;
        return ans;
    }
};