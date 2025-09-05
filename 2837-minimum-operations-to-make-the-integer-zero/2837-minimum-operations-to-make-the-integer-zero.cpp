class Solution {
public:

    bool isPowerOfTwo(int n) 
    {
        if (n <= 0) return false; // Powers of two are positive integers.
        return (n & (n - 1)) == 0;
    }

    int makeTheIntegerZero(int num1, int num2) 
    {
        if(num1<num2)
         return -1;

        // ans = (num1 - (sum of powers of 2))/nums2 
        // num1 - ans*nums2 = pow(2, ans achievable first power of 2)

        int k = 0;
        for(k=0;k<=60;k++)
        {
            long long x = num1 - 1LL*k*num2;
            if(x<k) return 
                -1;

            if(k>=__builtin_popcountll(x))
                return k;
        }


        return -1;
    }
};