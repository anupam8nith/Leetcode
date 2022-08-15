class Solution {
public:
    int i=0, j=0;
    int minimumTotal(vector<vector<int> > &tri) 
    {
        int n = tri.size();
        
        
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        dp[0][0]= tri[0][0];
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<i+1;j++)
            {
                if(j==0)
                    dp[i][j]= dp[i-1][j] + tri[i][j];
                else if(j==i)
                    dp[i][j]= dp[i-1][j-1] + tri[i][j];
                else
                {
                    if(dp[i][j]==0)
                    dp[i][j]= min(dp[i-1][j-1],dp[i-1][j]) +tri[i][j];
                    else
                        dp[i][j]= min(dp[i][j],min(dp[i-1][j-1],dp[i-1][j])) + tri[i][j];
                }
                    
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
                cout<<dp[a][b]<<" ";
            
            cout<<endl;
        }
        
    
        return *min_element(dp[n-1].begin(),dp[n-1].end());    
        }
};