class Solution {
public:
    
    int dp[38];
    
    int find(int n)
    {
        if( n<0 || n>37)
            return 0;
        
       if(dp[n]!=0)
            return dp[n];

        if(n>=3)
        dp[n]= dp[n-1]+dp[n-2]+dp[n-3];
        
        return dp[n] = find(n-1) + find(n-2) + find(n-3);;
    }
    
    int tribonacci(int n) 
    {
        dp[1]=1;
        dp[2]=1;
        
        if(dp[n]!=0)
            return dp[n];
        
        return find(n);
        
        
    }
};