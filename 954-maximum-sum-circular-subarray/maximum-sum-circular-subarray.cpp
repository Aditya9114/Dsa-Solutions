class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int num : nums) {
            // Standard Kadane's for max
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            // Kadane's variant for min
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);

            totalSum += num;
        }

        // If all numbers are negative, circular sum isn't valid
        // (would be empty array), so return maxSum
        return (totalSum == minSum) ? maxSum : max(maxSum, totalSum - minSum);
    }
};