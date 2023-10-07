class Solution {
public:
    int dp[51][101][51];
int numOfArrays(int n, int m, int k) 
    {
        long long MOD=1e9+7;
        if (k < 1 || k > m || k > n) return 0;
    
        if (n == 1) return m;
    
        if (dp[n][m][k]) return dp[n][m][k];
    
        int ans = 0;
    
        for (int i = 1; i <= m; ++i) 
        {
            ans += numOfArrays(n-1, m, k) - numOfArrays(n-1, i-1, k);
            
            if (ans >= MOD) ans -= MOD;
            else if (ans < 0) ans += MOD;
            
            ans += numOfArrays(n-1, i-1, k-1);
            
            if (ans >= MOD) ans -= MOD;
        }
    
        dp[n][m][k] = ans;
        return ans;
    }
};