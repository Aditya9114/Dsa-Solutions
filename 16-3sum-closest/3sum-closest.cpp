class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> array(3);
        int i, j, k;
        int n = nums.size();
        int minDiff = INT_MAX;
        int closestSum;
        for (i = 0; i < n - 2; i++) {
            j = i + 1;
            k = n - 1;
            while (k > j) {
                int sum = nums[i] + nums[j] + nums[k]; 
                int diff = abs(target - sum);

                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return closestSum;
    }
};