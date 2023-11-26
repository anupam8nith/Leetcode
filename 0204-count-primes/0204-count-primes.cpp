class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }

        vector<int> strikes(n, 1);

        strikes[0] = 0;
        strikes[1] = 0;

        for (int i = 2; i <= sqrt(n); ++i) {
            if (strikes[i] != 0) {
                for (int j = i * i; j < n; j += i) {
                    strikes[j] = 0;
                }
            }
        }

        return accumulate(strikes.begin(), strikes.end(), 0);
    }
};
