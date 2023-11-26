class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        
        int m = matrix.size(), n = matrix[0].size();int ans = 0;
        
        for (int x = 0; x<m; x++)
        {
            for(int y = 0; y<n; y++)
                if(matrix[x][y] != 0 && x > 0)
                    matrix[x][y] += matrix[x-1][y];
            
            vector<int> ones = matrix[x]; sort(ones.begin(), ones.end());
            
            for(int i=0; i<n;i++) ans = max(ans, ones[i] * (n-i));
        }
        return ans;
    }
};