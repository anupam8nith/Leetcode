class Solution {
public:
    int i=0;
    
    int f(vector<int>&dp, int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        dp[0]=0;
        dp[1]=1;
        
        //if already calculated
        
        if(dp[n]!=-1)  return dp[n];
        else
        {
            return dp[n]= f(dp,n-1)+f(dp,n-2);
        }
    }
    
    int fib(int n) 
    {
        if(n<=1)
            return n;
        
        vector<int> dp(n+1,-1);
        
        int a=f(dp,n);
        
        return a;
    }
};