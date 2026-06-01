class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int len = cost.size();
        int counter = 0;
        int ans = 0;
        for(int i=len-1; i>=0; i--){
            if(counter == 2){
                counter = 0;
                continue;
            }
            ans += cost[i];
            counter++;
        }
        return ans;
    }
};