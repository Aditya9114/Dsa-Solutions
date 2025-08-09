int upperBound(vector<int> &nums, int target, int n){
	int low,high,mid;
        low = 0;
        high = nums.size()-1;  
        int ans = n;  
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;	
}