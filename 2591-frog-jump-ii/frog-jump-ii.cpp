class Solution {
public:
    int maxJump(vector<int>& stones) {
        int m = INT_MIN;
        int curr = 0;
        int n = stones.size();
        unordered_map<int,int> mpp;
        for(int i=2; i<n;i+=2){
            m = max(m,abs(stones[curr]-stones[i]));
            curr= i;
            mpp[i] = 1;
        } 
        if(curr!=n-1){
            m = max(abs(stones[curr]-stones[n-1]),m);
            curr = n-1;
            mpp[n-1] = 1;
        }
        if(mpp[n-2]!=1){
            m = max(abs(stones[curr]-stones[n-2]),m);
            curr = n-2;
        }
        while(curr>1){
            m = max(abs(stones[curr]-stones[curr-2]),m);
            curr = curr-2;
        }
        if(curr!=0){
            m = max(abs(stones[curr]-stones[curr-1]),m);
            curr = 0;
        }
        return m;
    }
};