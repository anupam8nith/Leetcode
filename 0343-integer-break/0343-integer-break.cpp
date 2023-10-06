class Solution {
public:
    int integerBreak(int n) 
    {
        // ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        if(n==2) return 1;if(n==3) return 2; int twos=0,threes=n/3;
    
        if(n>3 && n%3==0) return ((int)pow(3,threes));
        
        else if(n%3==1)
        {
            threes--;twos+=2;
        }
        else twos++;
        
        return (int)(pow(2,twos)*pow(3,threes));
    }
};

// class Solution {
// public:
//     int solve(int n , vector<int>&dp){
//         if(n<=3)return n;
//         if(dp[n]!= -1)return dp[n];
//         int maxi = INT_MIN;
//         for(int i=2;i<n;i++){
//             maxi = max(maxi, i* solve(n-i, dp));
//         }
//         return dp[n] = maxi;
//     }
//     int integerBreak(int n) {
//         if(n<=3)return n-1;
//         vector<int>dp(n+1, -1);
//         return solve(n, dp);
//     }
// };