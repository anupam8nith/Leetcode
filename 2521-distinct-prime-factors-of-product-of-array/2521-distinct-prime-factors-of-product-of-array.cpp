class Solution {
public:
    vector<int> primes;
   
    int distinctPrimeFactors(vector<int>& nums) 
    {
        unordered_set<int>s;
        if(primes.size()==0)primes= SieveOfAtkin(1e4);
        
        for(auto& n: nums)
        {
            for(int i=0;i<primes.size();i++)
            {
                if(primes[i]>n)break;
                else if(n%primes[i]==0)s.insert(primes[i]);
            }
        }
        
        return s.size();
    }
    
    
vector<int> SieveOfAtkin(int limit) 
{
        vector<bool> isPrime(limit + 1, false);
        vector<int> primes;

        // Mark small primes
        if (limit >= 2) primes.push_back(2);
        if (limit >= 3) primes.push_back(3);

        // Initialize sieve arrays
        vector<bool> sieve(limit + 1, false);

        int sqrtLimit = static_cast<int>(sqrt(limit));
        for (int x = 1; x <= sqrtLimit; x++) {
            for (int y = 1; y <= sqrtLimit; y++) {
                int n = (4 * x * x) + (y * y);
                if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                    sieve[n] = !sieve[n];

                n = (3 * x * x) + (y * y);
                if (n <= limit && (n % 12 == 7))
                    sieve[n] = !sieve[n];

                n = (3 * x * x) - (y * y);
                if (x > y && n <= limit && (n % 12 == 11))
                    sieve[n] = !sieve[n];
            }
        }

        for (int n = 5; n <= sqrtLimit; n++) {
            if (sieve[n]) {
                int sqrN = n * n;
                for (int k = sqrN; k <= limit; k += sqrN) {
                    sieve[k] = false;
                }
            }
        }

        // Collect primes
        for (int i = 5; i <= limit; i++) {
            if (sieve[i])
                primes.push_back(i);
        }

        return primes;
}
};