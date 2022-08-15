class Solution {
public:
    
    int solve(vector<vector<int>> &dp, int m, int n, vector<vector<int>> &grid)
    {
        // if(i==0 && j==0)
        // {
        //     dp[0][0] = grid[0][0];
        //     return dp[i][j];
        // }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1)
                    dp[i][j]=grid[i-1][j-1]+dp[i][j-1];
                else if(j==1)
                    dp[i][j]= grid[i-1][j-1] + dp[i-1][j];
                else 
                    dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
                
            }
        }
       
        
        return dp[m][n];
        
        
        
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int i=0,j=0;
        
        
        vector <vector<int>> dp(m+1 , vector <int> (n+1 ,0));
        
        return solve(dp,m,n,grid);
        
    }
};