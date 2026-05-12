class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int low = 0;
        int high = 1e9;
        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int energy = mid;

            bool possible = true;

            for(int i = 0; i < tasks.size(); i++) {

                if(energy < tasks[i][1]) {
                    possible = false;
                    break;
                }

                energy -= tasks[i][0];
            }

            if(possible) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};