class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        int mid;
        int minnum=INT_MAX;
        while(low<=high){
            mid = (low+high)/2;

            //left sorted
            if(nums[low]<=nums[mid]){
                minnum = min(minnum,nums[low]);
                low = mid + 1;
            }
            //right sorted
            else{
                minnum = min(minnum,nums[mid]);
                high = mid-1;
            }
        }
        return minnum;
    }
};