class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, n));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                int same = 0, diff = 0;
                for (int l = i; l > 0; --l) {
                    if (s[l-1] == s[i-1])
                        ++same;
                    else
                        ++diff;
                    if (j-diff >= 0)
                        dp[i][j] = min(dp[i][j], dp[l-1][j-diff] + 1 + (same >= 100 ? 3 : same >= 10 ? 2 : same >= 2 ? 1 : 0));
                }
            }
        }
        return dp[n][k];
    }
};