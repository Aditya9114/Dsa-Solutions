class Solution {
public:
    int minOperations(string s) {
        int len = s.size();
        char bit = s[0];
        string newString;
        for(int i=0;i<len;i++){
            newString+=bit;
            if(bit == '0')bit = '1';
            else bit = '0';
        }
        string newString2;
        bit = '0';
        if(s[0] == '0')bit = '1';
        for(int i=0;i<len;i++){
            newString2+=bit;
            if(bit == '0')bit = '1';
            else bit = '0';
        }
        int ans1 = 0, ans2 = 0, res = 0;
        for(int i=0;i<len;i++){
            if(newString[i]!=s[i])ans1++;
            if(newString2[i]!=s[i])ans2++;
        }
        res = min(ans1,ans2);
        return res;
    }
};