class Solution {
public:
    int dp[31];
    
    int fib(int n) 
    {
        if(dp[n]!=0)return dp[n];
        if(n==0)return 0;
        if(n==1) return 1;
        
        return dp[n] = fib(n-1) + fib(n-2);
    }
};