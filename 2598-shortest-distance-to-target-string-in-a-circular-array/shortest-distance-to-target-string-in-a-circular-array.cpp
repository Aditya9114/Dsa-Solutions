class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target)return 0;
        int left = (startIndex-1 + n) % n;
        int right = (startIndex+1) % n;
        int leftCount = 1;
        int rightCount = 1;
        int loopCount = 1;
        int flag = 0;
        while(loopCount != (n-1)){
            if(words[left] == target || words[right] == target){
                flag=1;
                break;      
            }
            leftCount++;
            rightCount++;
            left = (left-1 +n) % n;
            right = (right+1) % n;
            loopCount++;
        } 
        if(flag == 0)return -1;
        return min(leftCount,rightCount);
    }
};