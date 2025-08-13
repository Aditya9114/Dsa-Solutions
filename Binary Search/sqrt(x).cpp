class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long high = x;
        long low = 1;
        long mid;
        int ans=1;
        while(low<=high){
            mid = (low+high)/2;
            if(mid*mid == x)return mid;
            else if(mid*mid < x){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};