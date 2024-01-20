class Solution 
{
public:
    bool isValid(int x, int y, int n)
    {
        if(x<n && y<n && x>=0 && y>=0) return true;
        
        return false;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = matrix.size();

        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int temp = INT_MAX;
                
                for(int k=0;k<n;k++)
                {
                    if(k==j)continue;
                    
                    if(isValid(i-1,k,n)) temp= min(temp,matrix[i-1][k]);
                }
                
                matrix[i][j]+=temp;
            }
        
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};
