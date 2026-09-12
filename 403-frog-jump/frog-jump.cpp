class Solution {
public:
    bool jump(vector<int>& stones, int pos, int j,
              unordered_map<int,int>& mpp,
              unordered_map<long long, bool>& dp) {
        
        if(mpp.find(pos) == mpp.end())
            return false;

        if(pos == stones[stones.size()-1])
            return true;

        long long key = ((long long)pos << 32) | j;

        if(dp.find(key) != dp.end())
            return dp[key];

        // jump j + 1
        if(jump(stones, pos+j+1, j+1, mpp, dp))
            return dp[key] = true;

        // jump j
        if(j > 0 && jump(stones, pos+j, j, mpp, dp))
            return dp[key] = true;

        // jump j - 1
        if(j > 1 && jump(stones, pos+j-1, j-1, mpp, dp))
            return dp[key] = true;

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mpp;
        
        for(int i = 0; i < stones.size(); i++) {
            mpp[stones[i]] = 1;
        }

        unordered_map<long long, bool> dp;

        return jump(stones, 0, 0, mpp, dp);
    }
};