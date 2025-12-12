class Solution {
public:
    typedef pair<int, pair<int,int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<P, vector<P>, greater<P>> pq;
        int m = nums1.size();
        int n = nums2.size();

        // visited states to avoid duplicates
        set<pair<int,int>> visited;

        // push (0,0)
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0,0});

        vector<vector<int>> result;

        while (k-- && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});

            // explore (i, j+1)
            if (j + 1 < n && visited.find({i, j+1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }

            // explore (i+1, j)
            if (i + 1 < m && visited.find({i+1, j}) == visited.end()) {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
        }

        return result;
    }
};
