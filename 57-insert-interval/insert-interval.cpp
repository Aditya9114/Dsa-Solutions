class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        // Handle empty cases
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.size() == 0) return intervals;
        
        int n = intervals.size();
        int i = 0;
        
        // Add all intervals that come before newInterval (no overlap)
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        // Merge all overlapping intervals with newInterval
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        // Add all intervals that come after newInterval (no overlap)
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};