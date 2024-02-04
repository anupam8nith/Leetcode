#include <vector>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        int d = 0;
        while (n > 0) {
            d++;
            n /= 10;
        }
        return d;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int startDigits = countDigits(low);
        int endDigits = countDigits(high);

        for (int digits = startDigits; digits <= endDigits; ++digits) {
            for (int i = 1; i <= 10 - digits; ++i) {
                int num = 0;
                for (int j = i; j < i + digits; ++j) {
                    num = num * 10 + j;
                }
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
