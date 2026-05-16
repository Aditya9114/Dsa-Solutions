class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            int oldMid = mid;
            if(nums[low] == nums[mid]){
                while(nums[low] == nums[mid]){
                    if(low == mid || low>mid)break;
                    low++;
                    mid--;
                }
                ans = min(ans,nums[low]);
                low = oldMid + 1;
            }
            else if(nums[high] == nums[mid]){
                while(nums[high] == nums[mid]){
                    if(high == mid || mid>high)break;
                    high--;
                    mid++;
                }
                ans = min(ans,nums[mid]);
                high = oldMid - 1;
            }
            else if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
            ans = min(ans,nums[mid]);
        }
        return ans;
    }
};