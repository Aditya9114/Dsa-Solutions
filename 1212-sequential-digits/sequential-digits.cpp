class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int firstDigit;
        vector<int> ans;

        int digits = 0;
        int ori = low;
        while (ori) {
            digits++;
            ori /= 10;
        }

        int highDigits = 0;
        ori = high;
        while (ori) {
            highDigits++;
            ori /= 10;
        }

        while (1) {
            int firstDigitOri = 0;

            while (1) {
                firstDigit = firstDigitOri + 1;
                firstDigitOri++;

                long long num = 0;
                bool valid = true;

                for (int i = 0; i < digits; i++) {
                    if (firstDigit > 9) {
                        valid = false;
                        break;
                    }

                    num = num * 10 + firstDigit;
                    firstDigit++;
                }

                if (!valid)
                    break;

                if (num >= low && num <= high) {
                    ans.push_back((int)num);
                }
            }

            digits++;
            if (digits > highDigits)
                break;
        }

        return ans;
    }
};