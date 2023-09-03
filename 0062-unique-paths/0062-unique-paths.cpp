class Solution {
public:
    int dp[100][100];
        
    int solve(int m, int n, int i, int j) {
        if (i == m - 1 && j == n - 1) return 1; // Reached the destination
        
        if (i < 0 || i >= m || j < 0 || j >= n) return 0; // Out of bounds
        
        if (dp[i][j] != 0) return dp[i][j];
        
        dp[i][j] = solve(m, n, i + 1, j) + solve(m, n, i, j + 1);
          
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1; // Only one row or one column
        
        return solve(m, n, 0, 0);
    }
};
