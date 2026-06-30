class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        int left = 0, right = 1;
        mpp[s[left]]++;
        int count = 0;
        int n = s.size();
        while(right < s.size()){
            mpp[s[right]]++;
            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0){
                count += n - right;
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};