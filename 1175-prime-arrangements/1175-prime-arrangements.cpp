class Solution 
{
public:
    int mod = 1e9 + 7;

    int factorial(int x) 
    {
        long long ans = 1;
        for (int i = 2; i <= x; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }

    int numPrimeArrangements(int n) 
    {
        int count = 0;

        for (int i = 2; i <= n; i++) 
        {
            bool flag = true;
            for (int j = 2; j * j <= i; j++) 
            {
                if (i % j == 0) 
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)count++;
        }

        int nonPrimes = n - count;
        long long arrangements = (long long)(factorial(count) % mod) * factorial(nonPrimes) % mod;

        return (int)arrangements;
    }
};
