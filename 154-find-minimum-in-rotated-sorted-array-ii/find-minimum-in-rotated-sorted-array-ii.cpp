class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Min is in right half (excluding mid)
                low = mid + 1;
            } 
            else if (nums[mid] < nums[high]) {
                // Mid could be the min, so keep it
                high = mid;
            } 
            else {
                // nums[mid] == nums[high]: can't tell which side
                // Safe to shrink high by 1 (we still have mid as a candidate)
                high--;
            }
        }

        return nums[low];
    }
};