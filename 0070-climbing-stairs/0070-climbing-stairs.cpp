class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int a = 1, b = 2;
        int curr;
        for (int i = 2; i < n; i++) {
          curr = a + b;
          a = b;
          b = curr;
        }
        return b;
    }
};