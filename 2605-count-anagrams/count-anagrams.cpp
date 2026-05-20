class Solution {
public:

    long long mod = 1e9 + 7;

    long long power(long long a, long long b) {

        long long ans = 1;

        while (b > 0) {

            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;

            b /= 2;
        }

        return ans;
    }

    int countAnagrams(string s) {

        vector<long long> fact(100001, 1);

        for (int i = 1; i < 100001; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        vector<int> alpha(26, 0);

        long long ans = 1;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {

                alpha[s[i] - 'a']++;
            }

            else {

                int len = accumulate(alpha.begin(), alpha.end(), 0);

                long long numerator = fact[len];

                long long denominator = 1;

                for (int j = 0; j < 26; j++) {
                    denominator = (denominator * fact[alpha[j]]) % mod;
                }

                ans = (ans * ((numerator * power(denominator, mod - 2)) % mod)) % mod;

                fill(alpha.begin(), alpha.end(), 0);
            }
        }

        int len = accumulate(alpha.begin(), alpha.end(), 0);

        long long numerator = fact[len];

        long long denominator = 1;

        for (int j = 0; j < 26; j++) {
            denominator = (denominator * fact[alpha[j]]) % mod;
        }

        ans = (ans * ((numerator * power(denominator, mod - 2)) % mod)) % mod;

        return ans;
    }
};