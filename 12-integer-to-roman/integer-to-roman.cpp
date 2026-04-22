class Solution {
public:
    string intToRoman(int num) {
        string ans;
        vector<int> numbers = {1000, 900, 500, 400, 100, 90, 50,
                               40,   10,  9,   5,   4,   1};
        vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                  "XL", "X",  "IX", "V",  "IV", "I"};
        while (num != 0) {
            int i = 0;
            while (numbers[i] > num) {
                i++;
            }
            int sub = numbers[i];
            string s = symbols[i];
            while(num >= sub){
                num = num - sub;
                ans+=s;
            }
        }
        return ans;
    }
};