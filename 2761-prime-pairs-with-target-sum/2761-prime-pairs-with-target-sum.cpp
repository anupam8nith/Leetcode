unordered_set<int> st;
vector<int> primes;
class Solution {
public:
    
    void getPrimes(int n)
    {
        bitset<1000000>isNotPrime;

        isNotPrime[0] = 1;
        isNotPrime[1] = 1;

        for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) 
        {
            if (isNotPrime[i] == 0) 
                for (int j = i * i; j < n; j += i) isNotPrime[j] = 1;
        }
        
        for(int i=2;i<n;i++)if(isNotPrime[i]==0) 
        { 
              st.insert(i); 
              primes.push_back(i); 
         }
        
        return;
    }
    
    vector<vector<int>> findPrimePairs(int n) 
    {
        ios_base::sync_with_stdio(false);cin.tie(0);
        if(st.size()==0)getPrimes(1000000);
        
        vector<vector<int>> ans;
        for(int i = 0; i < primes.size() && primes[i] <= n/2; ++i)
            if(st.find(n - primes[i]) != st.end()) 
            {  ans.push_back({primes[i], n - primes[i]});  }
        
        return ans;
    }
};