class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) 
    {
        vector<bool> isNotPrime(n,false);
        isNotPrime[1]=true;
        
        for(int i=2;i<n;i++)
        {
            if(isNotPrime[i])continue;
            
            for(long multiple = (long)i*i;multiple<n;multiple+=i)isNotPrime[multiple]=true;
        }
        
        vector<vector<int>> ans;
        
        for(int i=2;i<n;i++)
        {
            if(isNotPrime[i])continue;
            else if(isNotPrime[n-i]==false)
            {ans.push_back({i,n-i});isNotPrime[n-i]=true;}
        }
        
        return ans;
    }
};