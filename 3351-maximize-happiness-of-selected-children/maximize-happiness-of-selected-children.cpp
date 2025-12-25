class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long maxHappiness = 0;
        int reducingFactor = 0;
        for(int i=0;i<k;i++){
            int value = happiness[i] - reducingFactor;
            if(value < 1){
                value = 0;
            }
            maxHappiness +=value;
            reducingFactor++;    
        }
        return maxHappiness;
    }
};