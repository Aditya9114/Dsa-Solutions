class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0;
        int prev = 1;
        if(n==1)return 1;
        int ans;
        for(int i=0; i<n; i++){
            ans = prev2+prev;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};