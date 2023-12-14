class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) \
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        
        int m = matrix.size(),n=matrix[0].size();
        
        if(m==n)
        {
            for(int i=0;i<matrix.size();i++)
                for(int j=0;j<i;j++)
                    swap(matrix[i][j],matrix[j][i]);
            
            return matrix;
        }
        else
        {
            vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size(), 0));
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    transposed[i][j]=matrix[j][i];
            
            return transposed;
        }
            
        
        return matrix;
        
    }
};