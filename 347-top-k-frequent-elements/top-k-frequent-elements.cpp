class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto& p : mpp) {
            int num = p.first;
            int freq = p.second;
            pq.push({freq,num});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans(k,-1);
        for(int i=0;i<k;i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};