#include <vector>
#include <cmath>

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        std::vector<bool> strikes(n, true);
        strikes[0] = strikes[1] = false;

        int count = n - 2; // All numbers are initially assumed to be prime except 0 and 1

        for (int i = 2; i * i < n; ++i) {
            if (strikes[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (strikes[j]) {
                        strikes[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};
