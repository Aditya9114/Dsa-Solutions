class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount = 0;
        int rightCount = 0;
        int blankCount = 0;

        for(int i=0; i<moves.size(); i++){
            if(moves[i] == 'L'){
                leftCount++;
            }
            else if(moves[i] == 'R'){
                rightCount++;
            }
            else{
                blankCount++;
            }
        }
        int LorR = max(leftCount,rightCount);
        int minLorR = min(leftCount,rightCount);
        return (LorR + blankCount) - minLorR;
    }
};