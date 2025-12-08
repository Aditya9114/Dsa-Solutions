class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxheap;
        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            int num = arr[i];
            maxheap.push({diff,num});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<int> ans(k,0);
        for(int i=k-1;i>=0;i--){
            ans[i] = maxheap.top().second;
            maxheap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};