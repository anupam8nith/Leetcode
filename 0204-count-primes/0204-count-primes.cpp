class Solution {
public:
    int countPrimes(int n) 
    {
        ios_base::sync_with_stdio(false);cout.tie(NULL);
        
        vector<bool> isNotPrime(n,false);
        
        int countPrime=0;
        
        for(int i=2;i<n;i++)
        {
            if(isNotPrime[i])continue;
            
            countPrime++;
            for(long multiple=(long)i*i ;multiple<n;multiple+=i)isNotPrime[multiple]=true;
        }
        
        return countPrime;
    }
};