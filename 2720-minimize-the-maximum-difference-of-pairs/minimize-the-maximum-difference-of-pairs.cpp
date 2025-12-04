class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            int countPairs = 0;
            for(int i = 0; i < n - 1; ) {
                if(nums[i+1] - nums[i] <= mid){
                    countPairs++;
                    i += 2;   
                } else {
                    i++;      
                }
            }

            if(countPairs >= p){
                ans = mid;         
                high = mid - 1;    
            }
            else{
                low = mid + 1;     
            }
        }
        
        return ans;
    }
};
