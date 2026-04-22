class Solution {
public:
    int romanToInt(string s) {
        int prev;
        int ans = 0;
        int inc = 0;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'I':
                inc = 1;
                break;
                
                case 'V':
                inc=5;
                break;

                case 'X':
                inc=10;
                break;

                case 'L':
                inc=50;
                break;

                case 'C':
                inc=100;
                break;

                case 'D':
                inc=500;
                break;

                case 'M':
                inc =1000;
                break;
            }
            if(i > 0 && prev < inc){
                ans = ans - prev;
                if(prev == 1 && inc == 5) ans += 4;
                else if(prev == 1 && inc == 10) ans +=9;
                else if(prev == 10 && inc == 50) ans +=40;
                else if(prev == 10 && inc == 100) ans+=90;
                else if(prev == 100 && inc == 500) ans +=400;
                else ans+=900;
            }
            else ans = ans + inc;
            prev = inc;
        }
        return ans;
    }
};