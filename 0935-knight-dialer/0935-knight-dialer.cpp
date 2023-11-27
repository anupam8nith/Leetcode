int dp[5001][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
vector<vector<int>> table = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
};
int MOD = 1e9 + 7;

class Solution {
public:
    int dfs(int n, int at) {
        if (dp[n][at] != 0) {
            return dp[n][at];
        }
        
        int ret = 0;
        for (const auto& from : table[at]) {
            ret = (ret + dfs(n - 1, from)) % MOD;
        }
        return dp[n][at] = ret;
    }
    int knightDialer(int n) {
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + dfs(n - 1, i)) % MOD;
        }
        return ans;
    }
};