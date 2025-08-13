class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       long high = *max_element(piles.begin(), piles.end());
        long low = 1;
        long mid;
        long ans;
        while(low<=high){
           mid = (low+high)/2;
           long count=0;
            for(int i=0;i<piles.size();i++){
                long x;
                x = piles[i]/mid;
                if(x>=1&&(piles[i]%mid>0)){
                    x++;
                }
                else if(x<1){
                    x = 1;
                }
                count = count + x;
            }
            if(count <= h){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};