class Solution 
{
public:
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size(),n2=nums2.size();
        
        vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));
        
        function<int(int, int)> calcdp = [&](int i, int j) 
        {
            if (i == n1 || j == n2) return INT_MIN;
            
            if (dp[i][j] != INT_MIN) return dp[i][j];
            
            dp[i][j] = max(nums1[i] * nums2[j] + max(calcdp(i + 1, j + 1), 0),max(calcdp(i + 1, j), calcdp(i, j + 1)));
            
            return dp[i][j];
            
        };   
        
        return calcdp(0,0);
    }
};