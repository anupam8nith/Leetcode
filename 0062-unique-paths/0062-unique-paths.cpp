class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; i++)
                    dp[i][0] = 1;
        for(int j = 0; j < n; j++)
                    dp[0][j] = 1;
        
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        
        return dp[m-1][n-1];    
    }
};

// class Solution {
// public:
//     int dp[100][100];
        
//     int solve(int m, int n, int i, int j) {
//         if (i == m - 1 && j == n - 1) return 1; // Reached the destination
        
//         if (i < 0 || i >= m || j < 0 || j >= n) return 0; // Out of bounds
        
//         if (dp[i][j] != 0) return dp[i][j];
        
//         dp[i][j] = solve(m, n, i + 1, j) + solve(m, n, i, j + 1);
          
//         return dp[i][j];
//     }
    
//     int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1) return 1; // Only one row or one column
        
//         return solve(m, n, 0, 0);
//     }
// };
