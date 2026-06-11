class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int>mpp;
        for(int i=0; i<nums.size();i++){
           sum += nums[i];
           if(sum == k)ans++;
           int need = sum - k;
           if(mpp.find(need)!= mpp.end()){
            ans+= mpp[need];
           }
           mpp[sum] += 1;
        }
        return ans;
    }
};