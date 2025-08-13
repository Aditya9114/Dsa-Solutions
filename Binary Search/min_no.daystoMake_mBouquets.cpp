class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long high = *max_element(bloomDay.begin(), bloomDay.end());
        long low = 0;
        int fsize = bloomDay.size();
        long long x;
        x = 1LL * m * k;  
        if(x>fsize)return -1;
        long mid;
        while(low<=high){
            mid = (low+high)/2;
            long count = 0;
            long bouquet = 0;
            for(long i=0;i<fsize;i++){
                if(mid>=bloomDay[i]){
                    count++;
                    if(count == k){
                        bouquet++;
                        count = 0;
                    }
                }
                else{
                    count = 0;
                }
            }
            if(bouquet >= m){   
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};