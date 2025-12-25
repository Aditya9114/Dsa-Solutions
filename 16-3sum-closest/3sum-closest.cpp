class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> array(3);
        int i, j, k;
        int n = nums.size();
        int ans1 = INT_MAX;
        int ans;
        for (i = 0; i < n - 2; i++) {
            j = i + 1;
            k = n - 1;
            while (k > j) {
                int sum = nums[i] + nums[j] + nums[k]; 
                int diff = abs(target - sum);

                if (diff < ans1) {
                    ans1 = diff;
                    ans = sum;
                }

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};