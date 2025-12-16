class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // FIXED: Keep priority_queue declaration on fewer lines
        priority_queue<pair<pair<int,int>, int>,
                       vector<pair<pair<int,int>, int>>,
                       greater<pair<pair<int,int>, int>>> pq; // SJF queue
        
        priority_queue<pair<pair<int,int>, int>,
                       vector<pair<pair<int,int>, int>>,
                       greater<pair<pair<int,int>, int>>> pq2; // sorted jobs 
        
        long long currTime = 0;
        int n = tasks.size();

        for(int i=0;i<n;i++){
            pq2.push({{tasks[i][0],tasks[i][1]},i});
        }

        vector<int> ans;
        while(!pq2.empty() || !pq.empty()){
            
            // Handle CPU idle time - jump to next task if pq is empty
            if(pq.empty() && !pq2.empty()){
                currTime = pq2.top().first.first;
            }
            
            // Add all tasks that have arrived by currTime
            while(!pq2.empty() && pq2.top().first.first <= currTime){
                int et = pq2.top().first.first;
                int pt = pq2.top().first.second;
                int in = pq2.top().second;
                pq.push({{pt,in},et});
                pq2.pop();
            }

            // Process only ONE task
            if(!pq.empty()){
                int ipt = pq.top().first.first;
                int index = pq.top().first.second;
                pq.pop();
                
                ans.push_back(index);
                currTime = currTime + ipt;

                // Insert tasks after a task is completed
                while((!pq2.empty()) && pq2.top().first.first <= currTime){
                    int et = pq2.top().first.first;
                    int pt = pq2.top().first.second;
                    int in = pq2.top().second;
                    pq2.pop();
                    pq.push({{pt,in},et});
                }  
            }
        }
        return ans;
    }
};