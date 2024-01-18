class Solution {
public:
    vector<int> dp;
    int count (int i)
    {
        if(i<0) return 0;
        else if(i<=1)return 1;
        else if(dp[i]!=0) return dp[i];
        else dp[i] = count(i-1) + count(i-2);
        
        return dp[i];
    }
    
    int climbStairs(int n) 
    {
        dp.resize(n+1);
        
        return count(n);
        
    }
};