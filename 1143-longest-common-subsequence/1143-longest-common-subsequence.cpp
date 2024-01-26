class Solution {
public:
    int longestCommonSubsequence(string a, string b) 
{
    short dp[2][1001] = {};

    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            dp[!(i&1)][j + 1] = a[i] == b[j] ? dp[i&1][j] + 1 : max(dp[i&1][j + 1], dp[!(i&1)][j]);
        
    return dp[a.size()&1][b.size()];
}
};