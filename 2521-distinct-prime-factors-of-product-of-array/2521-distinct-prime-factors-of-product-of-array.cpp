#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> primes;
    
    void PrimeSieve(int n) 
    {
        vector<bool> isNotPrime(n + 1, false);

        isNotPrime[0] = true;
        isNotPrime[1] = true;
        isNotPrime[2] = false;

        for (int i = 3; i * i <= n; ++i)
            if (!isNotPrime[i])
                for (int j = i * i; j <= n; j += i)
                    isNotPrime[j] = true;

        for (int i = 2; i <= n; ++i)
            if (!isNotPrime[i]) primes.push_back(i);
    }
   
    int distinctPrimeFactors(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);cin.tie(0);
        
        set<int> s;
        if (primes.empty()) PrimeSieve(*max_element(nums.begin(), nums.end()));
        
        for (auto& n: nums) 
        {
            for (auto& p: primes) 
            {
                if (p * p > n) break;
                
                if (n % p == 0) 
                {
                    s.insert(p);
                    while (n % p == 0) n /= p; // Remove all occurrences of this prime factor
                }
            }
            
            if (n > 1) s.insert(n); // If the remaining value is a prime factor
        }
        
        return s.size();
    }
};
