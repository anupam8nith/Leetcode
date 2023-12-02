class Solution {
public:
    vector<int> primes;
    
    void PrimeSieve(int n)
    {
        bitset<1000000>isNotPrime;

        isNotPrime[0] = 1;isNotPrime[1] = 1;

        for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) 
            if (isNotPrime[i] == 0) 
                for (int j = i * i; j < n; j += i) 
                    isNotPrime[j] = 1;
        
        for(int i=2;i<n;i++)if(isNotPrime[i]==0) primes.push_back(i); 
    }
   
    int distinctPrimeFactors(vector<int>& nums) 
    {
        set<int>s;
        if(primes.size()==0)PrimeSieve(1e4);
        
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
};
