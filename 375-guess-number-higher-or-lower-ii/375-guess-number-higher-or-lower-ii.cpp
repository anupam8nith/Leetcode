class Solution {
public:
    int dp[201][201];
    
    int fun(int l, int r)
    {
        if(l>=r)
            return 0;
        
        //check if the ans is there
        
        if(dp[l][r]!=0)
            return dp[l][r];
        
        //else
       int  ans = INT_MAX;
        
        for(int x = l;x<=r;x++)
        {
            ans = min(ans, x + max(fun(l,x-1), fun(x+1, r)));
        }
        
        dp[l][r] = ans;
        
        return ans;
    }
    
    
    
    int getMoneyAmount(int n) 
    {
        memset(dp,0,201*201*sizeof(int));
        int answer = fun(1,n);
        
        // for(int i=1;i<n+1;i++)
        //     cout<<" "<<dp[1][i];
        
        return answer;
    }
};



//best dp solution

// class Solution {
// public:
//     int dp[201][201];
//     int helper(int l, int r){
//         if(l>=r)    
//             return 0;
//         if(dp[l][r]!=0)
//             return dp[l][r];
//         int ans = INT_MAX;
//         for(int x=l; x<=r; x++){
//             ans = min(ans, x + max(helper(l, x-1), helper(x+1, r)) );
//         }
//         dp[l][r] = ans;
//         return ans;
//     }
//     int getMoneyAmount(int n) {
//         memset(dp, 0, 201*201*sizeof(int));
//         return helper(1, n);        
//     }
// };