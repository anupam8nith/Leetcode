class Solution {
public:
    int dp[1001];

    int solve(vector<int>& cost, int i) 
    {
        if (i < 0) return 0;
        if (dp[i] != 0) return dp[i];

        dp[i] = min(solve(cost, i - 1) + cost[i], solve(cost, i - 2) + cost[i]);

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();

        return min(solve(cost, n - 1), solve(cost, n - 2));
    }
};