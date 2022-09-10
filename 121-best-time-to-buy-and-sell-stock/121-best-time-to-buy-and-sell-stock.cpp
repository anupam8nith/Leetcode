class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int min_price = prices[0];
        
        int ans = 0;
        for (int i=1; i<n; i++) {
            if (prices[i] >= min_price) {
                ans = max(ans, prices[i] - min_price);
            } else {
                min_price = min(min_price, prices[i]);
            }
        }
        return ans;
    }
};

//DP Solution
// class Solution {
// public:
//     int dp[100001][3];
//     int rec(vector<int>& prices,int i,int n,int k,bool buy)
//     {

//         if(i>=n or k<=0)
//             return 0;
//         if(dp[i][buy]!=-1) return dp[i][buy];
        
//         if(buy)//buy
//         {
//             return dp[i][buy]=max(-prices[i]+rec(prices,i+1,n,k,!buy),rec(prices,i+1,n,k,buy));
//         }
//         else//sell 
//         {
//              return dp[i][buy]=max(prices[i]+rec(prices,i+1,n,k-1,!buy),rec(prices,i+1,n,k,buy));
//         }
        
//     }
//     int maxProfit(vector<int>& prices) {
//         memset(dp,-1,sizeof(dp));
//         int n=prices.size();
//         return rec(prices,0,n,1,1);
//     }
// };


//code 1

// ios::sync_with_stdio(false);
//         cin.tie(0);
//         cout.tie(0);
        
        
//       int select=0, profit=INT_MIN,max_profit=0;
        
        
        
//         for(long int i=0;i<prices.size();i++)
//         {
//             if(prices[select]>prices[i])
//                 select=i;
//             else
//                 max_profit= max(max_profit, prices[i]-prices[select]);
//         }
        
//         return max_profit;