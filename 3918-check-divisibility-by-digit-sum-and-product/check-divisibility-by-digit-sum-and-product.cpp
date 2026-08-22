class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        int sum = 0, prod = 1;
        while(n){
            int d = n % 10;
            n = n/10;
            sum+=d;
            prod*=d;
        }
        if(ori % (sum+prod) == 0)return true;
        return false;
    }
};