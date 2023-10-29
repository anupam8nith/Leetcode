class Solution 
{
public:
    
    vector<vector<int>> v = {{1,2,4}, {0,2}, {1,3}, {2}, {2,3}};
    int mod=1e9+7;
    
    int countVowelPermutation(int n) 
    {
        if(n==1)
        return 5;
        
        vector<vector<long>> dp(n,vector<long>(5,0));
        
        dp[0][0]=1; dp[0][1]=1; dp[0][2]=1; dp[0][3]=1; dp[0][4]=1;
        
        long sum=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                for(int k=0;k<v[j].size();k++)
                dp[i][j]+=(dp[i-1][v[j][k]]%mod);
                
                if(i==n-1)
                sum+=(dp[i][j]);
            }
        }
        return sum%mod;
    }
};
// 3 2 2 1 2
// 6 5 3 2 3
// 11 9 7 3 5
// 21 18 12 7 10
// 40 33 25 12 19