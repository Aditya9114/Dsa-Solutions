class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        int totalEnergyRequired = 0;
        int totalEnergy = 0;

        for(int i = 0; i < tasks.size(); i++) {
            totalEnergyRequired += tasks[i][0];
            totalEnergy += tasks[i][1];
        }

        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int low = totalEnergyRequired;
        int high = totalEnergy;

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int energy = mid;

            int flag = 0;

            for(int i = 0; i < tasks.size(); i++) {

                if(energy < tasks[i][1]) {
                    flag = 1;
                    break;
                }

                energy -= tasks[i][0];
            }

            if(flag == 1) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};