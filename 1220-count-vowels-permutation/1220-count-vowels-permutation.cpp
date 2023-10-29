class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
         long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9)+7;
        long a2, e2, i2, o2, u2; 
        
        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
};


// class Solution 
// {
// public:
    
//     vector<vector<int>> vec = {{1,2,4}, {0,2}, {1,3}, {2}, {2,3}};
//     int MOD=1e9+7;
    
//     int countVowelPermutation(int n) 
//     {
//         if(n==1)
//         return 5;
        
//         vector<vector<long>> dp(n,vector<long>(5,0));
        
//         dp[0][0]=1; dp[0][1]=1; dp[0][2]=1; dp[0][3]=1; dp[0][4]=1;
        
//         long sum=0;
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<5;j++)
//             {
//                 for(int k=0;k<vec[j].size();k++)
//                 dp[i][j]+=(dp[i-1][vec[j][k]]%MOD);
                
//                 if(i==n-1)
//                 sum+=(dp[i][j]);
//             }
//         }
//         return sum%MOD;
//     }
// };
// // 3 2 2 1 2
// // 6 5 3 2 3
// // 11 9 7 3 5
// // 21 18 12 7 10
// // 40 33 25 12 19