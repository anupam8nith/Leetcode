class Solution {
public:
    vector<vector<short>> dp;

    int lcs(string& a, string& b, int i, int j) {
        if (i == a.size() || j == b.size()) return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (a[i] == b[j]) 
            return dp[i][j] = 1 + lcs(a, b, i + 1, j + 1);

        return dp[i][j] = max(lcs(a, b, i, j + 1), lcs(a, b, i + 1, j));
    }

    int longestCommonSubsequence(string a, string b) 
    {
        dp.assign(a.size(), vector<short>(b.size(), -1));
        
        return lcs(a, b, 0, 0);
    }
};