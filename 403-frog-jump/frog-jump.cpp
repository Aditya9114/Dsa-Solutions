class Solution {
public:
    void jump(vector<int>& stones, int pos, int jumpSize,
              unordered_map<int,int>& stoneMap,
              map<pair<int,int>, bool>& dp,
              int &flag) {

        if(stoneMap.find(pos) == stoneMap.end())
            return;

        if(flag == 1)
            return;

        if(pos == stones.back()) {
            flag = 1;
            return;
        }

        // Already visited this state
        if(dp[{pos, jumpSize}])
            return;

        dp[{pos, jumpSize}] = true;

        if(pos == 0) {
            jump(stones, pos + 1, jumpSize + 1,
                 stoneMap, dp, flag);
        }

        jump(stones, pos + jumpSize + 1, jumpSize + 1,
             stoneMap, dp, flag);

        if(jumpSize > 0) {
            jump(stones, pos + jumpSize, jumpSize,
                 stoneMap, dp, flag);
        }

        if(jumpSize > 1) {
            jump(stones, pos + jumpSize - 1, jumpSize - 1,
                 stoneMap, dp, flag);
        }
    }

    bool canCross(vector<int>& stones) {

        int flag = 0;

        unordered_map<int,int> stoneMap;
        map<pair<int,int>, bool> dp;

        for(int stone : stones) {
            stoneMap[stone] = 1;
        }

        jump(stones, 0, 0, stoneMap, dp, flag);

        return flag == 1;
    }
};