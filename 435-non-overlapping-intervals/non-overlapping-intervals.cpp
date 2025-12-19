class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][1],intervals[i][0]});
        }
        int ans = 0;
        int lastEnd = pq.top().first;
        pq.pop();
        while(!pq.empty()){
            if(pq.top().second < lastEnd){
                ans++;
                pq.pop();
                continue;
            }
            lastEnd = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};