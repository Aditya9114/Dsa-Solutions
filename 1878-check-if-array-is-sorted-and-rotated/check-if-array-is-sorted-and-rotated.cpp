class Solution {
public:
    // Aditya
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        if (n == 2) return true; 
        int l = 1, r;
        while (l < n) {
            if (nums[l] >= nums[l - 1]) {
                l++;
            } else {
                l = l - 1;
                break;
            }
        }
        if (l == n) return true;

        r = n - 1;
        while (r > l + 1) {
            if (nums[r] >= nums[r - 1]) {
                r--;
            } else {
                return false;
            }
        }
        if (nums.back() > nums[0]) return false;

        return true;
    }
};