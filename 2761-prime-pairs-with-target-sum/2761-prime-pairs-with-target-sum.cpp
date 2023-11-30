class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        
        bitset<1000000>isNotPrime;

        isNotPrime[0] = 1;
        isNotPrime[1] = 1;

        for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) 
        {
            if (isNotPrime[i] == 0) 
                for (int j = i * i; j < n; j += i) isNotPrime[j] = 1;
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