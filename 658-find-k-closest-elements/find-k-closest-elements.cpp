class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int> maxheap;
        if (arr.size() == 1)
            return arr;
        priority_queue<int, vector<int>, greater<int>> minheap;
        vector<int> ans(k, -1);
        int index = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            index = floorIndex(arr, x);
        }
        
        // Handle case where all elements are greater than x
        if (index >= 0) {
            for (int i = index; i >= 0; i--) {
                maxheap.push(arr[i]);
            }
        }
        
        for (int i = index + 1; i < arr.size(); i++) {
            minheap.push(arr[i]);
        }
        
        for (int i = 0; i < k; i++) {
            if (maxheap.empty()) {
                ans[i] = minheap.top();
                minheap.pop();
            } else if (minheap.empty()) {
                ans[i] = maxheap.top();
                maxheap.pop();
            } else if (abs(maxheap.top() - x) <= abs(minheap.top() - x)) {
                ans[i] = maxheap.top();
                maxheap.pop();
            } else {
                ans[i] = minheap.top();
                minheap.pop();
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    int floorIndex(vector<int>& arr, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);

        if (it != arr.end() && *it == x)
            return it - arr.begin();

        if (it == arr.begin())
            return -1;

        return (it - arr.begin()) - 1;
    }
};