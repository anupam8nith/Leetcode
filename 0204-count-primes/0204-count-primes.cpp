class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n < 2) return 0;

        bitset<5000001> strikes;

        strikes[0] = 1;
        strikes[1] = 1;

        for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) 
        {
            if (strikes[i] == 0) 
                for (int j = i * i; j < n; j += i) strikes[j] = 1;
        }

        return n-strikes.count();
    }
};
