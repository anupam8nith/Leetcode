class Solution {
public:
    bool isPowerOfThree(int n) 
    {   // best of the solution 
        // if(n<= 0)return false;
        // return 1162261467%n == 0;
        
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};