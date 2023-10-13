import java.util.Arrays;

class Solution 
{
    int[] dp = new int[1001];

    public int solve(int[] cost, int i) 
    {
        if (i < 0) return 0;
        if (dp[i] != 0) return dp[i];

        dp[i] = Math.min(solve(cost, i - 1) + cost[i], solve(cost, i - 2) + cost[i]);

        return dp[i];
    }

    public int minCostClimbingStairs(int[] cost) 
    {
        int n = cost.length;

        return Math.min(solve(cost, n - 1), solve(cost, n - 2));
    }

}