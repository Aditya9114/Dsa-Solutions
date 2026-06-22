class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(int i=0; i<text.size();i++){
            mpp[text[i]]++;
        }
        int count = 0;
        while(mpp['b'] >= 1 && mpp['a'] >=1 && mpp['l'] >= 2 && mpp['o'] >= 2 && mpp['n'] >=1){
            mpp['b'] -= 1;
            mpp['a'] -= 1;
            mpp['l'] -= 2;
            mpp['o'] -= 2;
            mpp['n'] -= 1;
            count++;
        }
        return count;
    }
};