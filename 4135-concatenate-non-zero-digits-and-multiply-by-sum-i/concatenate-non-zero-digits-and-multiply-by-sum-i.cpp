class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        long long sum=0;
        string s = to_string(n);
        for(int i=0; i<s.size();i++){
            int value = s[i] - '0';
            if(value == 0)continue;
            num = num*10 + value;
        }
        int ori = num;
        while(num){
            sum += num % 10;
            num = num/10;
        }
        return sum*ori;
    }
};