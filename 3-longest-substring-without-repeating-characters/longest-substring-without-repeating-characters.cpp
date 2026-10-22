class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charHash;
        int left = 0, right = 0;
        int ans = 0;
        int len = 0;
        while(right != s.size()){
            len++;
            charHash[s[right]]+=1;
            while(charHash[s[right]] > 1){
                charHash[s[left]] -= 1;
                left++;
                len--;
            }
            right++;
            ans = max(ans,len);
        }
        return ans;
    }
};