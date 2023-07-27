class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        if(n>batteries.size()) return 0;
        
        long long ans =0;
        sort(batteries.begin(),batteries.end());
        
        if(n==batteries.size()) return batteries[0];
            
            
        int k=0; int sz = batteries.size();
        long long sum = accumulate(batteries.begin(),batteries.end(),0L);
        
        while(batteries[sz-1-k]>sum/(n-k)) sum-=batteries[sz-1-k++];
        
        return sum/(n-k);
        
    }
};