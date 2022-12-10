class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        //condition to remain 1 is not having zero in row and columns
        
        int i=0,j=0, m = matrix.size(), n= matrix[0].size();
        
        vector<pair<int,int>> v;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                v.push_back({i,j});
            }
        }
        
        for(auto a: v)
        {
            int x = a.first;
            int y = a.second;
            
            // row zero
            
            for(int k=0;k<n;k++)
                matrix[x][k]=0;
            
            for(int k=0;k<m;k++)
                matrix[k][y]=0;
        }
        
        
        return;
        
    }
};