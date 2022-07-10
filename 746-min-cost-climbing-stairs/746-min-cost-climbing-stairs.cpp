//solution 1 (8ms easy)

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n = cost.size();
//         for(int i=2;i<n;i++)
//         {
//             cost[i] += min(cost[i-1],cost[i-2]);
//         }
//         return min(cost[n-1],cost[n-2]);
//     }
// };

class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>& dp){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(f(i+1,cost,dp),f(i+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0] = 0;
        dp[1] = cost[0];
        for(int i=1; i<cost.size(); i++){
            dp[i+1] = cost[i] + min(dp[i],dp[i-1]);
        }
        return min(dp[cost.size()-1],dp[cost.size()]);
    }
};