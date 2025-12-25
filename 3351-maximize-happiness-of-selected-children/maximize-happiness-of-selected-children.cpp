class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<happiness.size();i++){
            minHeap.push(happiness[i]);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        long long maxHappiness = 0;
        int reducingFactor = k-1;
        for(int i=0;i<k;i++){
            int value = minHeap.top() - reducingFactor;
            if(value < 1){
                value = 0;
            }
            maxHappiness +=value;
            reducingFactor--; 
            minHeap.pop();
        }
        return maxHappiness;
    }
};